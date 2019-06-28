[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Firewall\\Adapter",
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 13,
                "char": 49
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\Event",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 14,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Firewall\\Adapter",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 16,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Firewall\\Exception",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 17,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\DispatcherInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 18,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionClass",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                "line": 19,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Firewall which depends on annotations and dispatcher\n *",
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Annotations",
        "abstract": 0,
        "final": 0,
        "extends": "Adapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeArgumentsNumber",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                        "line": 30,
                        "char": 40
                    },
                    "docblock": "**\n     * Number of active active arguments in active annotation\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "annotationsAdapter",
                    "docblock": "**\n     * Adapter for annotations\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 36,
                            "char": 39
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 36,
                            "char": 45
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 41,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "dispatcher",
                    "docblock": "**\n     * Dispatcher\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "resolvedRole",
                    "docblock": "**\n     * Role for which access was granted\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 51,
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
                            "name": "annotationsAdapter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 52,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 52,
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
                                    "property": "annotationsAdapter",
                                    "expr": {
                                        "type": "variable",
                                        "value": "annotationsAdapter",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 54,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 54,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Firewall\\Adapter\\Annotations constructor\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 52,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "beforeExecuteRoute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "event",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Event",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 57,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 57,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "dispatcher",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DispatcherInterface",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 57,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 57,
                            "char": 87
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 57,
                            "char": 97
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 59,
                                    "char": 19
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 59,
                                    "char": 31
                                },
                                {
                                    "variable": "cacheKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 59,
                                    "char": 41
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 59,
                                    "char": 52
                                },
                                {
                                    "variable": "controllerClass",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 59,
                                    "char": 69
                                },
                                {
                                    "variable": "controllerName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 60,
                                    "char": 27
                                },
                                {
                                    "variable": "defaultAccess",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 60,
                                    "char": 42
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 60,
                                    "char": 57
                                },
                                {
                                    "variable": "role",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 60,
                                    "char": 63
                                },
                                {
                                    "variable": "singleRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 60,
                                    "char": 75
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 61,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 63,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeArgumentsNumber",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 63,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 63,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 65,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "dispatcher",
                                    "expr": {
                                        "type": "variable",
                                        "value": "dispatcher",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 65,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 65,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaultAccess",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 66,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultAccess",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 66,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 66,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 66,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 66,
                                    "char": 60
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
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 67,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 67,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 67,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 67,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 67,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 67,
                                    "char": 72
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "controllerName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dispatcher",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 68,
                                            "char": 45
                                        },
                                        "name": "getControllerName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 68,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 68,
                                    "char": 65
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "controllerClass",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dispatcher",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 69,
                                            "char": 45
                                        },
                                        "name": "getControllerClass",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 69,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 69,
                                    "char": 66
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "actionName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dispatcher",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 70,
                                            "char": 45
                                        },
                                        "name": "getActionName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 70,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 70,
                                    "char": 61
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "resolvedRole",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 71,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 71,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dispatcher",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 72,
                                            "char": 45
                                        },
                                        "name": "getDI",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 72,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 72,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 74,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 74,
                                            "char": 17
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRole",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 74,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 74,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 74,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 74,
                                    "char": 38
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 74,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "alwaysResolvingRole",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 74,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 74,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 74,
                                "char": 66
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeRole",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 75,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 75,
                                            "char": 44
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeIdentity",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 76,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 76,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 78,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 78,
                                            "char": 18
                                        },
                                        "name": "callRoleCallback",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 78,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 78,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 78,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 79,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 81,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "role",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 81,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRole",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 81,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 81,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 81,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 82,
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
                                        "value": "role",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 82,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 82,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 82,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 82,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "role",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 83,
                                        "char": 36
                                    },
                                    "value": "singleRole",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "cacheKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "singleRole",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 84,
                                                                        "char": 43
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "!",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 84,
                                                                        "char": 47
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 84,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "controllerName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 84,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 84,
                                                                "char": 64
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 84,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 84,
                                                            "char": 68
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "actionName",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 84,
                                                            "char": 80
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 84,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 84,
                                                    "char": 80
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "access",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 85,
                                                            "char": 37
                                                        },
                                                        "name": "getAccessFromCache",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "cacheKey",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 85,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 85,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 85,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 85,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 87,
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
                                                        "value": "access",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 87,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 87,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "boolean",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 87,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 87,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 89,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 90,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 91,
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
                                            "variable": "cacheKey",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "role",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 92,
                                                                "char": 33
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 92,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 92,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "controllerName",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 92,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 92,
                                                        "char": 54
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 92,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 92,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 92,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 92,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 92,
                                            "char": 70
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "access",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 93,
                                                    "char": 33
                                                },
                                                "name": "getAccessFromCache",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "cacheKey",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 93,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 93,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 93,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 93,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 96,
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
                                            "value": "role",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 96,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 96,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 96,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 96,
                                    "char": 35
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "role",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 96,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 96,
                                        "char": 50
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 96,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 96,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 96,
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
                                                        "type": "string",
                                                        "value": "When using firewall based on annotations you must pass ",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 98,
                                                        "char": 73
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "role as string, array or object implementing 'RoleAware'.",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 100,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 100,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 100,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 100,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 101,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 103,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 103,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "annotationsAdapter",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 103,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 103,
                                    "char": 38
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 103,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 103,
                                "char": 45
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
                                                        "value": "You need to set annotations adapter for firewall based ",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 105,
                                                        "char": 73
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "on annotations configurator to work",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 107,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 107,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 107,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 107,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 108,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 110,
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
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 110,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 110,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 110,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 110,
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
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 111,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "firewall:beforeCheck",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 111,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 111,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 111,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 111,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 111,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 112,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 114,
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
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 114,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 114,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 114,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 114,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "access",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 115,
                                                    "char": 31
                                                },
                                                "name": "checkControllerAnnotationAccess",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "controllerClass",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 116,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 116,
                                                        "char": 32
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "controllerName",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 117,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 117,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "role",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 119,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 119,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 119,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 119,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 121,
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
                                                "value": "access",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 121,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 121,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "boolean",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 121,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 121,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "access",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 122,
                                                            "char": 35
                                                        },
                                                        "name": "checkActionAnnotationAccess",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "controllerClass",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 123,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 123,
                                                                "char": 36
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "controllerName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 124,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 124,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "actionName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 125,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 125,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 127,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 127,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 127,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 127,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 128,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 130,
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
                                                "value": "access",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 130,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 130,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "boolean",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 130,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 130,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "access",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "defaultAccess",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 131,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 131,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 133,
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
                                                        "value": "role",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 133,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 133,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 133,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 133,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "role",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 134,
                                                        "char": 44
                                                    },
                                                    "value": "singleRole",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 135,
                                                                    "char": 30
                                                                },
                                                                "name": "saveAccessInCache",
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
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "singleRole",
                                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                            "line": 136,
                                                                                            "char": 40
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "string",
                                                                                            "value": "!",
                                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                            "line": 136,
                                                                                            "char": 44
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                        "line": 136,
                                                                                        "char": 44
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "controllerName",
                                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                        "line": 136,
                                                                                        "char": 61
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 136,
                                                                                    "char": 61
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "!",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 136,
                                                                                    "char": 65
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 136,
                                                                                "char": 65
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "actionName",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 136,
                                                                                "char": 77
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 136,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 136,
                                                                        "char": 77
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "access",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 138,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 138,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 138,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 139,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 140,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 141,
                                                            "char": 26
                                                        },
                                                        "name": "saveAccessInCache",
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
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "role",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 142,
                                                                                    "char": 30
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "!",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 142,
                                                                                    "char": 34
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 142,
                                                                                "char": 34
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "controllerName",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 142,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 142,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "!",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 142,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 142,
                                                                        "char": 55
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "actionName",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 142,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 142,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 142,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "access",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 144,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 144,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 144,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 145,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 146,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 147,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 149,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 149,
                                            "char": 26
                                        },
                                        "name": "fireEventOrThrowException",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "role",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 150,
                                                    "char": 17
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 150,
                                                "char": 17
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 151,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 151,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "controllerName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 152,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 152,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "access",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 154,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 154,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 154,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 154,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 156,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 156,
                                    "char": 20
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 156,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 156,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 157,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 158,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 159,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 57,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDispatcher",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 166,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "dispatcher",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 166,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 166,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Dispatcher",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 165,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 164,
                    "last-line": 169,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkControllerAnnotationAccess",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerClass",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 169,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 169,
                            "char": 101
                        },
                        {
                            "type": "parameter",
                            "name": "role",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 169,
                            "char": 111
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotationsAdapter",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 171,
                                    "char": 31
                                },
                                {
                                    "variable": "reflector",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 171,
                                    "char": 42
                                },
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 171,
                                    "char": 55
                                },
                                {
                                    "variable": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 171,
                                    "char": 63
                                },
                                {
                                    "variable": "singleRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 171,
                                    "char": 75
                                },
                                {
                                    "variable": "resolvedRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 172,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 174,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotationsAdapter",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 174,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotationsAdapter",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 174,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 174,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 174,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reflector",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotationsAdapter",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 175,
                                            "char": 53
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "controllerClass",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 175,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 175,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 175,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 175,
                                    "char": 74
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflector",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 176,
                                            "char": 44
                                        },
                                        "name": "getClassAnnotations",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 176,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 176,
                                    "char": 66
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "access",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 177,
                                            "char": 39
                                        },
                                        "name": "checkAnnotations",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "annotations",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 177,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 177,
                                                "char": 68
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "role",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 177,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 177,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 177,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 177,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 179,
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
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 179,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 179,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 179,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 179,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 180,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "activeArgumentsNumber",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 180,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 180,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 180,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 180,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "resolvedRole",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 181,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "resolvedRole",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 181,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 181,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 181,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 183,
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
                                                        "value": "resolvedRole",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 183,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 183,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 183,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 183,
                                                "char": 49
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "resolvedRole",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 184,
                                                        "char": 52
                                                    },
                                                    "value": "singleRole",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 185,
                                                                    "char": 30
                                                                },
                                                                "name": "saveAccessInCache",
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
                                                                                        "value": "singleRole",
                                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                        "line": 186,
                                                                                        "char": 40
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": "!",
                                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                        "line": 186,
                                                                                        "char": 44
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 186,
                                                                                    "char": 44
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "controllerName",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 186,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 186,
                                                                                "char": 61
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "!*",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 186,
                                                                                "char": 65
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 186,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 186,
                                                                        "char": 65
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "access",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 188,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 188,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 188,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 189,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 190,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 191,
                                                            "char": 26
                                                        },
                                                        "name": "saveAccessInCache",
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
                                                                                "value": "resolvedRole",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 192,
                                                                                "char": 38
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "!",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 192,
                                                                                "char": 42
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 192,
                                                                            "char": 42
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "controllerName",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 192,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 192,
                                                                        "char": 59
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "!*",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 192,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 192,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 192,
                                                                "char": 63
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "access",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 194,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 194,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 194,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 195,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 196,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 197,
                                                    "char": 22
                                                },
                                                "name": "saveAccessInCache",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "*!",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 198,
                                                                    "char": 24
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "controllerName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 198,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 198,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!*",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 198,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 198,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 198,
                                                        "char": 45
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 200,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 200,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 200,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 201,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 202,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 204,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 204,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 205,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 169,
                    "last-line": 207,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkAnnotations",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "annotations",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 207,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "role",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 207,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "returnAllow",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 209,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 211,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "annotations",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 211,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 211,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 211,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 212,
                                            "char": 28
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Allow",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 212,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 212,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 212,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "returnAllow",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 213,
                                                            "char": 40
                                                        },
                                                        "name": "handleAnnotation",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "annotations",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 214,
                                                                        "char": 33
                                                                    },
                                                                    "name": "get",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "Allow",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 214,
                                                                                "char": 43
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 214,
                                                                            "char": 43
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 214,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 214,
                                                                "char": 44
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 215,
                                                                    "char": 25
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 215,
                                                                "char": 25
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 217,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 217,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 217,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 217,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 219,
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
                                                        "value": "returnAllow",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 219,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 219,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "boolean",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 219,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 219,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "returnAllow",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 220,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 221,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 222,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 224,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 224,
                                            "char": 28
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Deny",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 224,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 224,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 224,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "returnAllow",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 225,
                                                            "char": 40
                                                        },
                                                        "name": "handleAnnotation",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "annotations",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 226,
                                                                        "char": 33
                                                                    },
                                                                    "name": "get",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "Deny",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 226,
                                                                                "char": 42
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 226,
                                                                            "char": 42
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 226,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 226,
                                                                "char": 43
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "false",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 227,
                                                                    "char": 26
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 227,
                                                                "char": 26
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 229,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 229,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 229,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 229,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 231,
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
                                                        "value": "returnAllow",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 231,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 231,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "boolean",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 231,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 231,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "returnAllow",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 232,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 233,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 234,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 235,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 237,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 237,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 238,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 207,
                    "last-line": 240,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkActionAnnotationAccess",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerClass",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 241,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 242,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 243,
                            "char": 26
                        },
                        {
                            "type": "parameter",
                            "name": "role",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 245,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotationsAdapter",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 247,
                                    "char": 31
                                },
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 247,
                                    "char": 44
                                },
                                {
                                    "variable": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 247,
                                    "char": 52
                                },
                                {
                                    "variable": "singleRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 247,
                                    "char": 64
                                },
                                {
                                    "variable": "resolvedRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 247,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 249,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotationsAdapter",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 249,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotationsAdapter",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 249,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 249,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 249,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotationsAdapter",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 250,
                                            "char": 53
                                        },
                                        "name": "getMethod",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "controllerClass",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 250,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 250,
                                                "char": 79
                                            },
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "actionName",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 250,
                                                        "char": 92
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "Action",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 250,
                                                        "char": 100
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 250,
                                                    "char": 100
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 250,
                                                "char": 100
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 250,
                                        "char": 101
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 250,
                                    "char": 101
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 252,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "access",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 252,
                                            "char": 27
                                        },
                                        "name": "checkAnnotations",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "annotations",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 252,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 252,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "role",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 252,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 252,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 252,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 252,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 254,
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
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 254,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 254,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 254,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 254,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 255,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "activeArgumentsNumber",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 255,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 255,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 255,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 255,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "resolvedRole",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 256,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "resolvedRole",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 256,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 256,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 256,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 258,
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
                                                        "value": "resolvedRole",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 258,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 258,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 258,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 258,
                                                "char": 49
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "resolvedRole",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 259,
                                                        "char": 52
                                                    },
                                                    "value": "singleRole",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 260,
                                                                    "char": 30
                                                                },
                                                                "name": "saveAccessInCache",
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
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "singleRole",
                                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                            "line": 261,
                                                                                            "char": 40
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "string",
                                                                                            "value": "!",
                                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                            "line": 261,
                                                                                            "char": 44
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                        "line": 261,
                                                                                        "char": 44
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "controllerName",
                                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                        "line": 261,
                                                                                        "char": 61
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 261,
                                                                                    "char": 61
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "!",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 261,
                                                                                    "char": 65
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 261,
                                                                                "char": 65
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "actionName",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 261,
                                                                                "char": 77
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 261,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 261,
                                                                        "char": 77
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "access",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 263,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 263,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 263,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 264,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 265,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 266,
                                                            "char": 26
                                                        },
                                                        "name": "saveAccessInCache",
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
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "resolvedRole",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 267,
                                                                                    "char": 38
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "!",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 267,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 267,
                                                                                "char": 42
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "controllerName",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 267,
                                                                                "char": 59
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 267,
                                                                            "char": 59
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "!",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 267,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 267,
                                                                        "char": 63
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "actionName",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 267,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 267,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 267,
                                                                "char": 75
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "access",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 269,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 269,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 269,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 270,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 271,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 272,
                                                    "char": 22
                                                },
                                                "name": "saveAccessInCache",
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
                                                                        "type": "string",
                                                                        "value": "*!",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 273,
                                                                        "char": 24
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "controllerName",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 273,
                                                                        "char": 41
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 273,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "!",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 273,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 273,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "actionName",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 273,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 273,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 273,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 275,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 275,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 275,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 276,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 277,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 279,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 279,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 280,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 240,
                    "last-line": 282,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAccessFromCache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 283,
                            "char": 20
                        },
                        {
                            "type": "parameter",
                            "name": "originalValues",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 284,
                                "char": 36
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 284,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "roleCacheKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 286,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 286,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "explodedKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 288,
                                    "char": 24
                                },
                                {
                                    "variable": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 288,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 290,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "access",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "getAccessFromCache",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 290,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 290,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 290,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 290,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 292,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 292,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 292,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 292,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 293,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 294,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 296,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "explodedKey",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "!",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 296,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 296,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 296,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 296,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 296,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 296,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 301,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "access",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "getAccessFromCache",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "explodedKey",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 302,
                                                                    "char": 24
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 302,
                                                                    "char": 26
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 302,
                                                                "char": 28
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 302,
                                                                "char": 32
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 302,
                                                            "char": 32
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "explodedKey",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 302,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 302,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 302,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 302,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!*",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 303,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 303,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 303,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 303,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 303,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 305,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 305,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 305,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 305,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 306,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 307,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 313,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "access",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "getAccessFromCache",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "*!",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 314,
                                                                "char": 16
                                                            },
                                                            "right": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "explodedKey",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 314,
                                                                    "char": 29
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 314,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 314,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 314,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "!",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 314,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 314,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "explodedKey",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 314,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "2",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 314,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 315,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 315,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 315,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 315,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 315,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 317,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 317,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 317,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 317,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 318,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 319,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 325,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "access",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "getAccessFromCache",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "*!",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 326,
                                                            "char": 16
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "explodedKey",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 326,
                                                                "char": 29
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 326,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 326,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 326,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!*",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 327,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 327,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 327,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 327,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 327,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 329,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 329,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 330,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 286,
                                "char": 15
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 287,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                        "line": 287,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 282,
                    "last-line": 332,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "handleAnnotation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "annotation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 332,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 332,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "role",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 332,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "numberArguments",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 334,
                                    "char": 28
                                },
                                {
                                    "variable": "annotationRoles",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 334,
                                    "char": 45
                                },
                                {
                                    "variable": "roleIntersect",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 334,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 336,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "numberArguments",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 336,
                                            "char": 54
                                        },
                                        "name": "numberArguments",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 336,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 336,
                                    "char": 72
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeArgumentsNumber",
                                    "expr": {
                                        "type": "variable",
                                        "value": "numberArguments",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 337,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 337,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 339,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "numberArguments",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 339,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 339,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                "line": 339,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "annotationRoles",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "annotation",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 340,
                                                        "char": 46
                                                    },
                                                    "name": "getArguments",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 340,
                                                    "char": 61
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 340,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 340,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 340,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 342,
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
                                                "value": "annotationRoles",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 342,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 342,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 342,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 342,
                                        "char": 48
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
                                                            "value": "role",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 343,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 343,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 343,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 343,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "in_array",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "role",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 343,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 343,
                                                            "char": 58
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "annotationRoles",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 343,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 343,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 343,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 343,
                                                "char": 77
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "resolvedRole",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "role",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 344,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 344,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 346,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "access",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 346,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 347,
                                                    "char": 17
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
                                                                "value": "role",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 347,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 347,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 347,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 347,
                                                        "char": 47
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "roleIntersect",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "array_intersect",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "role",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 348,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 348,
                                                                                "char": 61
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "annotationRoles",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                    "line": 348,
                                                                                    "char": 78
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 348,
                                                                                "char": 78
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 348,
                                                                        "char": 79
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 348,
                                                                    "char": 79
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 350,
                                                            "char": 22
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "bool",
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "roleIntersect",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 350,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 350,
                                                                "char": 45
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "object-property",
                                                                            "operator": "assign",
                                                                            "variable": "this",
                                                                            "property": "resolvedRole",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "roleIntersect",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 351,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 351,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 353,
                                                                    "char": 30
                                                                },
                                                                {
                                                                    "type": "return",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "access",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 353,
                                                                        "char": 38
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 354,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 355,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 355,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 355,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 355,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 355,
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
                                                                    "property": "resolvedRole",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "role",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 356,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 356,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 358,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "return",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 358,
                                                                "char": 32
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 359,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 361,
                                                    "char": 22
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 361,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 361,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 362,
                                            "char": 13
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
                                                        "value": "annotationRoles",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 362,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 362,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 362,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 362,
                                                "char": 55
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
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 363,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 363,
                                                                "char": 33
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "string",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 363,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 363,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "annotationRoles",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 363,
                                                                "char": 62
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "role",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 363,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 363,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 363,
                                                        "char": 69
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "resolvedRole",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "role",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 364,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 364,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 366,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "return",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "access",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 366,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 367,
                                                            "char": 17
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
                                                                        "type": "typeof",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "role",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 367,
                                                                            "char": 39
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 367,
                                                                        "char": 39
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "array",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 367,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 367,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "in_array",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "annotationRoles",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 367,
                                                                                "char": 74
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 367,
                                                                            "char": 74
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "role",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 367,
                                                                                "char": 80
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 367,
                                                                            "char": 80
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 367,
                                                                    "char": 82
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 367,
                                                                "char": 82
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "object-property",
                                                                            "operator": "assign",
                                                                            "variable": "this",
                                                                            "property": "resolvedRole",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "annotationRoles",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 368,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 368,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 370,
                                                                    "char": 26
                                                                },
                                                                {
                                                                    "type": "return",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "access",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 370,
                                                                        "char": 34
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 371,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 371,
                                                            "char": 24
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "access",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 371,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "bool",
                                                                    "value": "false",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 371,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                "line": 371,
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
                                                                            "property": "resolvedRole",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "role",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                                "line": 372,
                                                                                "char": 50
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                            "line": 372,
                                                                            "char": 50
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 374,
                                                                    "char": 26
                                                                },
                                                                {
                                                                    "type": "return",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                        "line": 374,
                                                                        "char": 32
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                                    "line": 375,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 377,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 377,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 377,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 378,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 378,
                                            "char": 18
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
                                                            "type": "string",
                                                            "value": "Allowed or denied role must be provided as string or array of roles.",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                            "line": 381,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 381,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 381,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 382,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 383,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "numberArguments",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 383,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 383,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 383,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "resolvedRole",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "role",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                        "line": 384,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 384,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 386,
                                            "char": 18
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "access",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 386,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                            "line": 387,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 387,
                                    "char": 14
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
                                                    "type": "string",
                                                    "value": "Allow or deny annotation expect one or none arguments",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                    "line": 390,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                                "line": 390,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                        "line": 390,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                                    "line": 391,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                            "line": 392,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
                    "line": 332,
                    "last-line": 393,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Annotations.zep",
        "line": 24,
        "char": 5
    }
]