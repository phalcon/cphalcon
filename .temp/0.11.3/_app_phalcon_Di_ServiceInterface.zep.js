[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Di",
        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents a service in the services container\n *",
        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ServiceInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "__set_state",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 23,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Restore the internal state of a service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                    "line": 23,
                                    "char": 80
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 23,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                        "line": 23,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefinition",
                    "docblock": "**\n     * Returns the service definition\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 28,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                        "line": 28,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 28,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParameter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 35,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Returns a parameter in a specific position\n     *\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isResolved",
                    "docblock": "**\n     * Returns true if the service was resolved\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 40,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                        "line": 40,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 40,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isShared",
                    "docblock": "**\n     * Check whether the service is shared or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 45,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                        "line": 45,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 45,
                    "last-line": 51,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "resolve",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 52,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 52,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 52,
                                "char": 70
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 52,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 52,
                            "char": 78
                        }
                    ],
                    "docblock": "**\n     * Resolves the service\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 52,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                        "line": 52,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 52,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefinition",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 57,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Set the service definition\n     *",
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 57,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setParameter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 62,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "parameter",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 62,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Changes a parameter in the definition without resolve the service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                    "line": 62,
                                    "char": 87
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                                "line": 62,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                        "line": 62,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 62,
                    "last-line": 66,
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
                            "name": "shared",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                            "line": 67,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Sets if the service is shared or not\n     *",
                    "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
                    "line": 67,
                    "last-line": 68,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
            "line": 68,
            "char": 1
        },
        "file": "\/app\/phalcon\/Di\/ServiceInterface.zep",
        "line": 0,
        "char": 0
    }
]