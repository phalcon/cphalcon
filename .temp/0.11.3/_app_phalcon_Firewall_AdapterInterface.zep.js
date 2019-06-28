[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Firewall",
        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\DispatcherInterface",
                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "alias": "CacheAdapterInterface",
                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                "line": 14,
                "char": 68
            }
        ],
        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Mvc\\Dispatcher\\Firewall adapters\n *",
        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "AdapterInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultAccess",
                    "docblock": "**\n     * Returns the default ACL access level\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                "line": 24,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                        "line": 24,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 24,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoleCallback",
                    "docblock": "**\n     * Gets role callback to fetch role name\n     *",
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 29,
                    "last-line": 33,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAlwaysResolvingRole",
                    "docblock": "**\n     * Gets always resolving role option\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                "line": 34,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                        "line": 34,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 34,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAlwaysResolvingRole",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "alwaysResolvingRole",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                            "line": 39,
                            "char": 68
                        }
                    ],
                    "docblock": "**\n     * Sets always resolving role option\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                        "line": 39,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 39,
                    "last-line": 43,
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
                                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                "line": 44,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                            "line": 44,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Sets cache backend\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                    "line": 44,
                                    "char": 82
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                "line": 44,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                        "line": 44,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 44,
                    "last-line": 48,
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
                            "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                            "line": 49,
                            "char": 55
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
                                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                    "line": 49,
                                    "char": 78
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                "line": 49,
                                "char": 78
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                        "line": 49,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 49,
                    "last-line": 53,
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
                            "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                            "line": 54,
                            "char": 49
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
                                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                    "line": 54,
                                    "char": 72
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                                "line": 54,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                        "line": 54,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
                    "line": 54,
                    "last-line": 55,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
            "line": 55,
            "char": 1
        },
        "file": "\/app\/phalcon\/Firewall\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]