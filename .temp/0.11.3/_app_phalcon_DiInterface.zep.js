[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/DiInterface.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/DiInterface.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\ServiceInterface",
                "file": "\/app\/phalcon\/DiInterface.zep",
                "line": 15,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Di\n *",
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "DiInterface",
        "extends": [
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/DiInterface.zep",
                "line": 21,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 29,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 29,
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 29,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 29,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Attempts to register a service in the services container\n     * Only is successful if a service hasn't been registered previously\n     * with the same name\n     *\n     * @param mixed definition\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 29,
                                    "char": 98
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 29,
                                "char": 98
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 29,
                                "char": 104
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 29,
                        "char": 104
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 29,
                    "last-line": 33,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 34,
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 34,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 34,
                            "char": 56
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 34,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 34,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 34,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getDefault",
                    "docblock": "**\n     * Return the last DI created\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 39,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 39,
                                "char": 58
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 39,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 39,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 39,
                    "last-line": 43,
                    "char": 26
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 44,
                            "char": 40
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 44,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 44,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 44,
                    "last-line": 48,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 49,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Returns the corresponding Phalcon\\Di\\Service instance for a service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 49,
                                    "char": 67
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 49,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 49,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 49,
                    "last-line": 53,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getServices",
                    "docblock": "**\n     * Return the services registered in the DI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 54,
                                    "char": 58
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 54,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 54,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 54,
                    "last-line": 58,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 59,
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 59,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 59,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Returns a shared service based on their configuration\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 59,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 59,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 59,
                    "last-line": 63,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 64,
                            "char": 37
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 64,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 64,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 64,
                    "last-line": 68,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 69,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Removes a service in the services container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 69,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 69,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "reset",
                    "docblock": "**\n     * Resets the internal default DI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 74,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 74,
                    "last-line": 78,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 79,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 79,
                            "char": 49
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 79,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 79,
                            "char": 70
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
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 79,
                                    "char": 93
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 79,
                                "char": 93
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 79,
                        "char": 93
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 79,
                    "last-line": 84,
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 85,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 85,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Set a default dependency injection container to be obtained into static\n     * methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 85,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 85,
                    "last-line": 89,
                    "char": 26
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 90,
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
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 90,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 90,
                            "char": 74
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
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 90,
                                    "char": 97
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 90,
                                "char": 97
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 90,
                        "char": 97
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 90,
                    "last-line": 94,
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
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 95,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/DiInterface.zep",
                            "line": 95,
                            "char": 55
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
                                    "file": "\/app\/phalcon\/DiInterface.zep",
                                    "line": 95,
                                    "char": 78
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/DiInterface.zep",
                                "line": 95,
                                "char": 78
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/DiInterface.zep",
                        "line": 95,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/DiInterface.zep",
                    "line": 95,
                    "last-line": 96,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/DiInterface.zep",
            "line": 96,
            "char": 1
        },
        "file": "\/app\/phalcon\/DiInterface.zep",
        "line": 0,
        "char": 0
    }
]