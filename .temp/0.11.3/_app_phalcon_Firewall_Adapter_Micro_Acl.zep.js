[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Firewall\\Adapter\\Micro",
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 14,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 15,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\Event",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 16,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 17,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Firewall\\Adapter",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 18,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Firewall\\Exception",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 19,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Micro",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 20,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\BinderInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 21,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router",
                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                "line": 22,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 26,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Firewall for Phalcon\\Mvc\\Micro which depends on ACL\n *",
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 27,
        "char": 5
    },
    {
        "type": "class",
        "name": "Acl",
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
                    "name": "aclServiceName",
                    "docblock": "**\n     * Acl service name\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 33,
                            "char": 35
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 33,
                            "char": 41
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 38,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "boundModels",
                    "docblock": "**\n     * Bound models\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 44,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "boundModelsKeyMap",
                    "docblock": "**\n     * Property used for setting different key names in associated ACL function\n     * than got from Binder\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 45,
                            "char": 38
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 45,
                            "char": 44
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "componentName",
                    "default": {
                        "type": "string",
                        "value": "Micro",
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                        "line": 51,
                        "char": 37
                    },
                    "docblock": "**\n     * Component name used to acquire access, be default it's Micro\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 51,
                            "char": 42
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 51,
                            "char": 48
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 56,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "micro",
                    "docblock": "**\n     * Micro object\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 62,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "roleCacheCallback",
                    "docblock": "**\n     * Function returning string for role cache key\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 63,
                            "char": 38
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 63,
                            "char": 44
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 68,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "router",
                    "docblock": "**\n     * Router object\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 75,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "routeNameConfiguration",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                        "line": 76,
                        "char": 45
                    },
                    "docblock": "**\n     * By default using route names which are required, you can change it to\n     * false to use route patterns\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 76,
                            "char": 51
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 78,
                    "char": 10
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
                            "name": "aclServiceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 78,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "boundModelsKeyMap",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 78,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 78,
                            "char": 88
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
                                    "property": "aclServiceName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "aclServiceName",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 80,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 80,
                                    "char": 53
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "boundModelsKeyMap",
                                    "expr": {
                                        "type": "variable",
                                        "value": "boundModelsKeyMap",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 81,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 81,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 82,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 78,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "afterBinding",
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 84,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 84,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "micro",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Micro",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 84,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 84,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 84,
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
                                    "property": "boundModels",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 86,
                                            "char": 39
                                        },
                                        "name": "getBoundModels",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 86,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 86,
                                    "char": 56
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "router",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 87,
                                            "char": 39
                                        },
                                        "name": "getRouter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 87,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 87,
                                    "char": 51
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "micro",
                                    "expr": {
                                        "type": "variable",
                                        "value": "micro",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 88,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 88,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 90,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 90,
                                    "char": 21
                                },
                                "name": "handleRouter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 90,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 90,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 90,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 91,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 84,
                    "last-line": 93,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 93,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 93,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "micro",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Micro",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 93,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 93,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 93,
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
                                    "property": "router",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 95,
                                            "char": 34
                                        },
                                        "name": "getRouter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 95,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 95,
                                    "char": 46
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "micro",
                                    "expr": {
                                        "type": "variable",
                                        "value": "micro",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 96,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 96,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 98,
                                    "char": 21
                                },
                                "name": "handleRouter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 98,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 98,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 98,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 93,
                    "last-line": 103,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMicro",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 106,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "micro",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 106,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 106,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 107,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets micro\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Micro",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 105,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 105,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                        "line": 105,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 104,
                    "last-line": 111,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isRouteNameConfiguration",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 114,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routeNameConfiguration",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 114,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 114,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 115,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets route name configuration\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 113,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                        "line": 113,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 112,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "fireEventOrThrowException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "role",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 121,
                            "char": 17
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 122,
                            "char": 26
                        },
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 123,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 125,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 127,
                                    "char": 26
                                },
                                {
                                    "variable": "roleName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 127,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 129,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 129,
                                "char": 19
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
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 130,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 130,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 130,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 130,
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
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 131,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "firewall:afterCheck",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 131,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 131,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 131,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 131,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 131,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 132,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 133,
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
                                                "value": "role",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 134,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 134,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 134,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 134,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "roleName",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "implode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": ", ",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 135,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 135,
                                                                "char": 42
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 135,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 135,
                                                                "char": 47
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 135,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 135,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 136,
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
                                                    "variable": "roleName",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "role",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 137,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 137,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 138,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 140,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 140,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "routeNameConfiguration",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 140,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 140,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 141,
                                                    "char": 29
                                                },
                                                "name": "throwFirewallException",
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
                                                                        "value": "Role name ",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 142,
                                                                        "char": 32
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "roleName",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 142,
                                                                        "char": 43
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 142,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " doesn't have access to route called ",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 142,
                                                                    "char": 83
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 142,
                                                                "char": 83
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "actionName",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 142,
                                                                "char": 95
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 142,
                                                            "char": 95
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 142,
                                                        "char": 95
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "403",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 144,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 144,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 144,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 145,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 146,
                                                    "char": 29
                                                },
                                                "name": "throwFirewallException",
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
                                                                        "value": "Role name ",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 147,
                                                                        "char": 32
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "roleName",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 147,
                                                                        "char": 43
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 147,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " doesn't have access to route with pattern ",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 147,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 147,
                                                                "char": 89
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "actionName",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 147,
                                                                "char": 101
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 147,
                                                            "char": 101
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 147,
                                                        "char": 101
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "403",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 149,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 149,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 149,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 150,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 151,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fires event or throwing exception\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 120,
                    "last-line": 154,
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
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 155,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 156,
                                "char": 36
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 156,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 158,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 158,
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
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 160,
                                    "char": 24
                                },
                                {
                                    "variable": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 160,
                                    "char": 32
                                },
                                {
                                    "variable": "keyWithValues",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 160,
                                    "char": 47
                                },
                                {
                                    "variable": "originalKeysJoin",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 160,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 162,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "roleCacheKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 162,
                                    "char": 26
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 162,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 162,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "roleCacheKey",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "!",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 163,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "roleCacheKey",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 163,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 163,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 163,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 164,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 166,
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
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 166,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 166,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 166,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 166,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 166,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 166,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 171,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "explodedKey",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 171,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 171,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 171,
                                    "char": 28
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 171,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "activeRole",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 171,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 171,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 171,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "explodedKey",
                                            "index-expr": [
                                                {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 172,
                                                    "char": 30
                                                }
                                            ],
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 172,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "activeRole",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 172,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 172,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 172,
                                            "char": 50
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "key",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "!",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 173,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 173,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "explodedKey",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 173,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 173,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 173,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 173,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 174,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 179,
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
                                        "value": "originalValues",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 179,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 179,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 179,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "originalKeysJoin",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "!",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 180,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 180,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "originalValues",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 180,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 180,
                                                        "char": 58
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 180,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 180,
                                            "char": 59
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "keyWithValues",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 181,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "!",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 181,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 181,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "originalKeysJoin",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 181,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 181,
                                                    "char": 63
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "roleCacheKey",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 181,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 181,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 181,
                                            "char": 77
                                        },
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
                                                            "value": "keyWithValues",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 182,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 182,
                                                        "char": 76
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 182,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 182,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 184,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 184,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 184,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 184,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "access",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 185,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 186,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 188,
                                    "char": 15
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
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "array-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "explodedKey",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                    "line": 189,
                                                                                    "char": 28
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "0",
                                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                    "line": 189,
                                                                                    "char": 30
                                                                                },
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                "line": 189,
                                                                                "char": 32
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "!",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                "line": 189,
                                                                                "char": 36
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 189,
                                                                            "char": 36
                                                                        },
                                                                        "right": {
                                                                            "type": "array-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "explodedKey",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                "line": 189,
                                                                                "char": 49
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "1",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                "line": 189,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 189,
                                                                            "char": 53
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 189,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "!*!",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 189,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 189,
                                                                    "char": 59
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "originalKeysJoin",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 189,
                                                                    "char": 78
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 189,
                                                                "char": 78
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "roleCacheKey",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 190,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 190,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 190,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 190,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 190,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 192,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 192,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 192,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 192,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "access",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 193,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 194,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 196,
                                    "char": 15
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
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 197,
                                                                            "char": 28
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 197,
                                                                            "char": 30
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 197,
                                                                        "char": 32
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "!*!*!",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 197,
                                                                        "char": 40
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 197,
                                                                    "char": 40
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "originalKeysJoin",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 197,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 197,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "roleCacheKey",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 198,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 198,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 198,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 198,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 198,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 200,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 200,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 200,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 200,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "access",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 201,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 202,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 203,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 205,
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
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 206,
                                                        "char": 17
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "roleCacheKey",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 207,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 207,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 207,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 207,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 207,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 209,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 209,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 209,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 209,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 210,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 211,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 217,
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
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "explodedKey",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 218,
                                                                        "char": 24
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 218,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 218,
                                                                    "char": 28
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "!",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 218,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 218,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "explodedKey",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 218,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 218,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 218,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 218,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "!*",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 218,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 218,
                                                        "char": 54
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "roleCacheKey",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 219,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 219,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 219,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 219,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 219,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 221,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 221,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 221,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 221,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 222,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 223,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 229,
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
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "explodedKey",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 230,
                                                                "char": 24
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 230,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 230,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "!*!*",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 230,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 230,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "roleCacheKey",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 231,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 231,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 231,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 231,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 231,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 233,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 233,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 234,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 158,
                                "char": 15
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 159,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 154,
                    "last-line": 236,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "handleRouter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "micro",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Micro",
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 236,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 236,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "acl",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 238,
                                    "char": 16
                                },
                                {
                                    "variable": "aclAccess",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 238,
                                    "char": 27
                                },
                                {
                                    "variable": "aclRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 238,
                                    "char": 36
                                },
                                {
                                    "variable": "aclServiceName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 238,
                                    "char": 52
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 238,
                                    "char": 64
                                },
                                {
                                    "variable": "boundModel",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 238,
                                    "char": 76
                                },
                                {
                                    "variable": "boundModelKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 239,
                                    "char": 26
                                },
                                {
                                    "variable": "boundModelKeyMap",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 239,
                                    "char": 44
                                },
                                {
                                    "variable": "boundModels",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 239,
                                    "char": 57
                                },
                                {
                                    "variable": "boundModelsKeyMap",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 239,
                                    "char": 76
                                },
                                {
                                    "variable": "cacheKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 240,
                                    "char": 21
                                },
                                {
                                    "variable": "componentName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 240,
                                    "char": 36
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 240,
                                    "char": 47
                                },
                                {
                                    "variable": "defaultAccess",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 240,
                                    "char": 62
                                },
                                {
                                    "variable": "modelBinder",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 240,
                                    "char": 75
                                },
                                {
                                    "variable": "originalValues",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 241,
                                    "char": 27
                                },
                                {
                                    "variable": "parameters",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 241,
                                    "char": 39
                                },
                                {
                                    "variable": "role",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 241,
                                    "char": 45
                                },
                                {
                                    "variable": "roleCacheKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 241,
                                    "char": 59
                                },
                                {
                                    "variable": "roleCacheCallback",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 241,
                                    "char": 78
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 242,
                                    "char": 18
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 242,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 244,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 244,
                                            "char": 31
                                        },
                                        "name": "getDI",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 244,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 244,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 245,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 245,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 245,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 245,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 245,
                                "char": 39
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
                                                    "value": "A dependency injector container is required to obtain ACL service",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 248,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 248,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 248,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 249,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 251,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
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
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 251,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultAccess",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 251,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 251,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 251,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 251,
                                    "char": 59
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parameters",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 252,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 252,
                                    "char": 35
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "route",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 253,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 253,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 253,
                                            "char": 46
                                        },
                                        "name": "getMatchedRoute",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 253,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 253,
                                    "char": 64
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "boundModels",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 254,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "boundModels",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 254,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 254,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 254,
                                    "char": 50
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "boundModelsKeyMap",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 255,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "boundModelsKeyMap",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 255,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 255,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 255,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 257,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 257,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "routeNameConfiguration",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 257,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 257,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "actionName",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 258,
                                                    "char": 36
                                                },
                                                "name": "getName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 258,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 258,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 259,
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
                                            "variable": "actionName",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 260,
                                                    "char": 36
                                                },
                                                "name": "getPattern",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 260,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 260,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 261,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 263,
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
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 263,
                                            "char": 17
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRole",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 263,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 263,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 263,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 263,
                                    "char": 38
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 263,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "alwaysResolvingRole",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 263,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 263,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 263,
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
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 264,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 264,
                                            "char": 44
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeIdentity",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 265,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 265,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 267,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 267,
                                            "char": 18
                                        },
                                        "name": "callRoleCallback",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 267,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 267,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 267,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 268,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 270,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "aclRole",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 270,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRole",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 270,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 270,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 270,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "componentName",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 271,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "componentName",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 271,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 271,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 271,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 273,
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
                                        "value": "aclRole",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 273,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 273,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 273,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 273,
                                "char": 37
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
                                                    "value": "When using ACL service as firewall configuration you can pass role only as string or object implementing 'Phalcon\\\\Acl\\\\RoleAware'.",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 276,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 276,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 276,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 277,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 280,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 280,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeIdentity",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 280,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 280,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 280,
                                    "char": 41
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 280,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 280,
                                "char": 50
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 281,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "activeIdentity",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 281,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 281,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 281,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 282,
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
                                            "variable": "role",
                                            "expr": {
                                                "type": "variable",
                                                "value": "aclRole",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 283,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 283,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 284,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 286,
                            "char": 11
                        },
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
                                                        "value": "aclRole",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 286,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 286,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 286,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 286,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 286,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "!",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 286,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 286,
                                            "char": 59
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "actionName",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 286,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 286,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 286,
                                    "char": 71
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "modelBinder",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "micro",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 287,
                                            "char": 33
                                        },
                                        "name": "getModelBinder",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 287,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 287,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 289,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "modelBinder",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 289,
                                    "char": 25
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 289,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 289,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "originalValues",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "modelBinder",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 290,
                                                    "char": 46
                                                },
                                                "name": "getOriginalValues",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 290,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 290,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 291,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 293,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "roleCacheCallback",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 293,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleCacheCallback",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 293,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 293,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 293,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 295,
                            "char": 10
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
                                            "value": "role",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 295,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 295,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 295,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 295,
                                    "char": 35
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "roleCacheCallback",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 295,
                                        "char": 56
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 295,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 295,
                                    "char": 63
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 295,
                                "char": 63
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "roleCacheKey",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "roleCacheCallback",
                                                "call-type": 2,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "role",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 296,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 296,
                                                        "char": 56
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 296,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 296,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 297,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 299,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "aclAccess",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 299,
                                            "char": 30
                                        },
                                        "name": "getAccessFromCache",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheKey",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 299,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 299,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "originalValues",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 299,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 299,
                                                "char": 74
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "roleCacheKey",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 299,
                                                    "char": 88
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 299,
                                                "char": 88
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 299,
                                        "char": 89
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 299,
                                    "char": 89
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 301,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "aclAccess",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 301,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 301,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 301,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "aclServiceName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 302,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "aclServiceName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 302,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 302,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 302,
                                            "char": 54
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "acl",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 303,
                                                    "char": 44
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "aclServiceName",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 303,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 303,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 303,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 303,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 305,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "acl",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 305,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 305,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 305,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 305,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "list",
                                                "left": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "acl",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 305,
                                                        "char": 55
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "\\Phalcon\\Acl\\AdapterInterface",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 305,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 305,
                                                    "char": 86
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 305,
                                                "char": 88
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 305,
                                            "char": 88
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 305,
                                        "char": 88
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
                                                                "value": "You need to add acl service to dependency injector ",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 307,
                                                                "char": 73
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "container which is implementing 'Phalcon\\\\Acl\\\\AdapterInterface'",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 309,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 309,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 309,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 309,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 310,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 313,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "acl",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 313,
                                                "char": 21
                                            },
                                            "name": "isRole",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "aclRole",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 313,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 313,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 313,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 313,
                                        "char": 38
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
                                                                    "value": "Role ",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 315,
                                                                    "char": 27
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "aclRole",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 315,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 315,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": " doesn't exist in ACL",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 316,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 316,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 316,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 316,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 317,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 320,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "acl",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 320,
                                                "char": 21
                                            },
                                            "name": "isComponent",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "componentName",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 320,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 320,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 320,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 320,
                                        "char": 49
                                    },
                                    "statements": [
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
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 321,
                                                            "char": 34
                                                        },
                                                        "name": "fireEventOrThrowException",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "aclRole",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 322,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 322,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "actionName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 323,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 323,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 324,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 324,
                                                                "char": 34
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "defaultAccess",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 326,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 326,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 326,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 326,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 328,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "roleCacheKey",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 328,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 328,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 328,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 329,
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
                                                                            "type": "variable",
                                                                            "value": "cacheKey",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 330,
                                                                            "char": 34
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "!",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 330,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 330,
                                                                        "char": 38
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "roleCacheKey",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 330,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 330,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 330,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "defaultAccess",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 332,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 332,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 332,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 333,
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
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 334,
                                                            "char": 26
                                                        },
                                                        "name": "saveAccessInCache",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "cacheKey",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 334,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 334,
                                                                "char": 53
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "defaultAccess",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 334,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 334,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 334,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 335,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 337,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 337,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 337,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 337,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 338,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 339,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 340,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 342,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "boundModels",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 342,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 342,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 342,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "boundModels",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 343,
                                                "char": 62
                                            },
                                            "key": "boundModelKey",
                                            "value": "boundModel",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "boundModelKeyMap",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 344,
                                                            "char": 81
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "boundModelsKeyMap",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 344,
                                                                "char": 65
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "boundModelKey",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 344,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 344,
                                                            "char": 81
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 344,
                                                        "char": 81
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "parameters",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "boundModelKeyMap",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 345,
                                                                            "char": 56
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "boundModel",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 345,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 345,
                                                                    "char": 70
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 346,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "parameters",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "boundModelKey",
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 347,
                                                                            "char": 53
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "boundModel",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                        "line": 347,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 347,
                                                                    "char": 67
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 348,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 349,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 350,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 352,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 352,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 352,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "aclAccess",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "acl",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 353,
                                                            "char": 37
                                                        },
                                                        "name": "isAllowed",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 353,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 353,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 353,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 353,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "actionName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 353,
                                                                    "char": 79
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 353,
                                                                "char": 79
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 353,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 353,
                                                    "char": 80
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 354,
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
                                                    "variable": "aclAccess",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "acl",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 355,
                                                            "char": 37
                                                        },
                                                        "name": "isAllowed",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 355,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 355,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 355,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 355,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "actionName",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 355,
                                                                    "char": 79
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 355,
                                                                "char": 79
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "parameters",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 355,
                                                                    "char": 91
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 355,
                                                                "char": 91
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 355,
                                                        "char": 92
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 355,
                                                    "char": 92
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 356,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 358,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "cacheKey",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "acl",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 358,
                                                    "char": 32
                                                },
                                                "name": "getActiveKey",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 358,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 358,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 360,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "acl",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 360,
                                                "char": 20
                                            },
                                            "name": "getActiveFunction",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 360,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 360,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 360,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "empty",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 361,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 361,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 361,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "greater",
                                                    "left": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "acl",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 361,
                                                            "char": 45
                                                        },
                                                        "name": "getActiveFunctionCustomArgumentsCount",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 361,
                                                        "char": 86
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 361,
                                                        "char": 90
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 361,
                                                    "char": 90
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 361,
                                                "char": 90
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "cacheKey",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "!",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 362,
                                                                    "char": 38
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "join",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "!",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                "line": 362,
                                                                                "char": 46
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 362,
                                                                            "char": 46
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "originalValues",
                                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                                "line": 362,
                                                                                "char": 62
                                                                            },
                                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                            "line": 362,
                                                                            "char": 62
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 362,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 362,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 362,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 363,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 365,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "roleCacheKey",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 365,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 365,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 365,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "role",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 365,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 365,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 365,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 365,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 365,
                                                "char": 66
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "cacheKey",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "!",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 366,
                                                                    "char": 38
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "roleCacheKey",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                    "line": 366,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                                "line": 366,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 366,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 367,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 368,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 370,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 370,
                                            "char": 18
                                        },
                                        "name": "saveAccessInCache",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheKey",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 370,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 370,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "aclAccess",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 370,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 370,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 370,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 371,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 373,
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
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 373,
                                            "char": 26
                                        },
                                        "name": "fireEventOrThrowException",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "aclRole",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 374,
                                                    "char": 20
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 374,
                                                "char": 20
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 375,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 375,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 376,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 376,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "aclAccess",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 378,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 378,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 378,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 378,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 380,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 380,
                                    "char": 20
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 380,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 380,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 381,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 382,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 383,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 236,
                    "last-line": 385,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "saveAccessInCache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 385,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 385,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "explodedKey",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 387,
                                    "char": 24
                                },
                                {
                                    "variable": "activeRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 387,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 389,
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
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 389,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 389,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 389,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 389,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 389,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 389,
                                    "char": 42
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "activeRole",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 390,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRole",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 390,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 390,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 390,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 396,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "explodedKey",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 396,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 396,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 396,
                                    "char": 28
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "activeRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 396,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 396,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "explodedKey",
                                            "index-expr": [
                                                {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                    "line": 397,
                                                    "char": 30
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "activeRole",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 397,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 397,
                                            "char": 44
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "key",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "!",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 398,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 398,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "explodedKey",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                            "line": 398,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                        "line": 398,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                                "line": 398,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 398,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                    "line": 399,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 401,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "saveAccessInCache",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 401,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 401,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                            "line": 401,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                        "line": 401,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                                "line": 401,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                            "line": 402,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                        "line": 386,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
                    "line": 385,
                    "last-line": 403,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
            "line": 27,
            "char": 5
        },
        "file": "\/app\/phalcon\/Firewall\/Adapter\/Micro\/Acl.zep",
        "line": 27,
        "char": 5
    }
]