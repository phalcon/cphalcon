[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Firewall",
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 14,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\RoleAware",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "alias": "CacheAdapterInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 16,
                "char": 68
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 17,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 18,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 19,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Dispatcher",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 20,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Adapter for Phalcon\\Firewall adapters\n *",
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 25,
        "char": 8
    },
    {
        "type": "class",
        "name": "Adapter",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "AdapterInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 25,
                "char": 51
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                "line": 26,
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
                    "name": "activeIdentity",
                    "docblock": "**\n     * Storing active identity object implementing Phalcon\/Acl\/RoleAware\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 30,
                            "char": 36
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeRole",
                    "docblock": "**\n     * Storing active user role\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 35,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 40,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "alwaysResolvingRole",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 41,
                        "char": 43
                    },
                    "docblock": "**\n     * Should role always be resolved using role callback or just once?\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 41,
                            "char": 49
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cache",
                    "docblock": "**\n     * Cache for caching access\n     * @var <CacheAdapterInterface>\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 52,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultAccess",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "Acl",
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 53,
                            "char": 41
                        },
                        "right": {
                            "type": "variable",
                            "value": "DENY",
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 53,
                            "char": 41
                        },
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 53,
                        "char": 41
                    },
                    "docblock": "**\n     * Default access\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 53,
                            "char": 47
                        }
                    ],
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 58,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "docblock": "**\n     * Events manager\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 64,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "internalCache",
                    "docblock": "**\n     * Internal cache for caching access during request time\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 71,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "roleCallback",
                    "docblock": "**\n     * Anonymous function for getting user identity - this function must\n     * return string, array or object implementing Phalcon\\Acl\\RoleAware\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 76,
                    "char": 6
                }
            ],
            "methods": [
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
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 79,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 79,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 79,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 80,
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
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 78,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 77,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoleCallback",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 87,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "roleCallback",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 87,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 87,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 88,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets role callback to fetch role name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Closure",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 86,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 86,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 85,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAlwaysResolvingRole",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 95,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "alwaysResolvingRole",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 95,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 95,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 96,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets always resolving role option\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 94,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 94,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 93,
                    "last-line": 100,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cache",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "CacheAdapterInterface",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 101,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 101,
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
                                    "property": "cache",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cache",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 103,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 103,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 105,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 105,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "internalCache",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 105,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 105,
                                    "char": 34
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 105,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 105,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "internalCache",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "cache",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 106,
                                                    "char": 45
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "_PHF_",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                            "line": 106,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 106,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 106,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 106,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 107,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 109,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 109,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 110,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cache adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 102,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 102,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 102,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 101,
                    "last-line": 114,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultAccess",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaultAccess",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 115,
                            "char": 55
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
                                    "property": "defaultAccess",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultAccess",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 117,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 117,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 119,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 119,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 120,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 116,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 116,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 116,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 115,
                    "last-line": 124,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 125,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 125,
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
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 127,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 127,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 129,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 129,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 130,
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
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 126,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 126,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 126,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 125,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRoleCallback",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "callback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 135,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "is_callable",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "callback",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 137,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 137,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 137,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 137,
                                "char": 35
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
                                                    "value": "Role callback must be function.",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 138,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 138,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 138,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 139,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 140,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "roleCallback",
                                    "expr": {
                                        "type": "variable",
                                        "value": "callback",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 140,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 140,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 142,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 142,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets role callback to fetch role name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 136,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 136,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 135,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "callRoleCallback",
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 145,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 145,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "roleCallback",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 147,
                                    "char": 25
                                },
                                {
                                    "variable": "identity",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 147,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 149,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "roleCallback",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 149,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleCallback",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 149,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 149,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 149,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "identity",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "roleCallback",
                                        "call-type": 2,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 150,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 150,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 150,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 150,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 152,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "identity",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 152,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 152,
                                "char": 27
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
                                                    "value": "Function defined as roleCallback must return something.",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 153,
                                                    "char": 88
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 153,
                                                "char": 88
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 153,
                                        "char": 89
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 154,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 156,
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
                                        "value": "identity",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 156,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 156,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 156,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 156,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "instanceof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "identity",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 157,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "RoleAware",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 157,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 157,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 157,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 157,
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
                                                            "type": "string",
                                                            "value": "Role passed as object must implement 'Phalcon\\\\Acl\\\\RoleAware'",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                            "line": 158,
                                                            "char": 99
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 158,
                                                        "char": 99
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 158,
                                                "char": 100
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 159,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 160,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeIdentity",
                                            "expr": {
                                                "type": "variable",
                                                "value": "identity",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 160,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 160,
                                            "char": 48
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeRole",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "identity",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 161,
                                                    "char": 49
                                                },
                                                "name": "getRoleName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 161,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 161,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 162,
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
                                            "property": "activeRole",
                                            "expr": {
                                                "type": "variable",
                                                "value": "identity",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 163,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 163,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 164,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 165,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 146,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 145,
                    "last-line": 169,
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
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 171,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 172,
                                "char": 36
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 172,
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 174,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 174,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 176,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 178,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "access",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 178,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 178,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "internalCache",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 178,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 178,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 178,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 178,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 178,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 180,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 180,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 181,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets access from cache\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 174,
                                "char": 15
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 170,
                    "last-line": 185,
                    "char": 22
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 186,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 186,
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
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 188,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 189,
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
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 189,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 189,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 189,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 189,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 189,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 189,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 190,
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
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 190,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 190,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 190,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 190,
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
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 191,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "firewall:beforeException",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 191,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 191,
                                                    "char": 60
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 191,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 191,
                                                    "char": 66
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "exception",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 191,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 191,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 191,
                                            "char": 81
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 191,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 191,
                                        "char": 89
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 192,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 193,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 194,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 195,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles a user exception\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 186,
                    "last-line": 199,
                    "char": 22
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
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 201,
                            "char": 17
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 202,
                            "char": 26
                        },
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 203,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 205,
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
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 207,
                                    "char": 26
                                },
                                {
                                    "variable": "roleName",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 207,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 209,
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
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 209,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 209,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 209,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 209,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 210,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "access",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 210,
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
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 211,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 211,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 211,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 211,
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
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 212,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "firewall:afterCheck",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                            "line": 212,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 212,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                            "line": 212,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 212,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 212,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 213,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 214,
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
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 215,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 215,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 215,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 215,
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
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                    "line": 216,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                "line": 216,
                                                                "char": 42
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                    "line": 216,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                "line": 216,
                                                                "char": 47
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 216,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 216,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 217,
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
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 218,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 218,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 219,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 221,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 221,
                                            "char": 25
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
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "Role name ",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                        "line": 222,
                                                                        "char": 28
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "roleName",
                                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                        "line": 222,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                    "line": 222,
                                                                    "char": 39
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " doesn't have access to action ",
                                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                    "line": 222,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                "line": 222,
                                                                "char": 73
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "actionName",
                                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                                "line": 223,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                            "line": 223,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": " in controller ",
                                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                            "line": 223,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 223,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "controllerName",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 223,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 223,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 223,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "403",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 225,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 225,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 225,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 226,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 227,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fires event or throwing exception\n     *",
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 200,
                    "last-line": 231,
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
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 232,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 232,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cache",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 234,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 236,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "internalCache",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 236,
                                            "char": 36
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 236,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 236,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cache",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 237,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 237,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 237,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 237,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 239,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "cache",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 239,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 239,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 239,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 240,
                                            "char": 19
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "_PHF_",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 240,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 240,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 240,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "internalCache",
                                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                        "line": 240,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 240,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 240,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 240,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 241,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 242,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Saves access in cache and internal cache\n    *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 233,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 232,
                    "last-line": 246,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "throwFirewallException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 247,
                            "char": 61
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
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 247,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 247,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exception",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 249,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 251,
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
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 251,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 251,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "exceptionCode",
                                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                    "line": 251,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 251,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 251,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 251,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 253,
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
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 253,
                                        "char": 17
                                    },
                                    "name": "handleException",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exception",
                                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                                "line": 253,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                            "line": 253,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 253,
                                    "char": 47
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 253,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 253,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                        "line": 254,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                    "line": 255,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 257,
                            "char": 13
                        },
                        {
                            "type": "throw",
                            "expr": {
                                "type": "variable",
                                "value": "exception",
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 257,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                            "line": 258,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Throws an internal exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                                "line": 248,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                        "line": 248,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
                    "line": 247,
                    "last-line": 259,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
            "line": 25,
            "char": 14
        },
        "file": "\/app\/phalcon\/Firewall\/Adapter.zep",
        "line": 25,
        "char": 14
    }
]