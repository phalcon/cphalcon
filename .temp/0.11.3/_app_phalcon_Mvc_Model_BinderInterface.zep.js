[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                "line": 13,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\BinderInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Binder\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "BinderInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "bindToHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "object",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                            "line": 25,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                            "line": 25,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "cacheKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                            "line": 25,
                            "char": 80
                        },
                        {
                            "type": "parameter",
                            "name": "methodName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                "line": 25,
                                "char": 107
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                            "line": 25,
                            "char": 107
                        }
                    ],
                    "docblock": "**\n     * Bind models into params in proper handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                "line": 25,
                                "char": 117
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                        "line": 25,
                        "char": 117
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBoundModels",
                    "docblock": "**\n     * Gets active bound models\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                "line": 30,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                        "line": 30,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCache",
                    "docblock": "**\n     * Gets cache instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                    "line": 35,
                                    "char": 53
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                "line": 35,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                        "line": 35,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                    "line": 35,
                    "last-line": 39,
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
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                "line": 40,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                            "line": 40,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Sets cache instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BinderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                    "line": 40,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                                "line": 40,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                        "line": 40,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
                    "line": 40,
                    "last-line": 41,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
            "line": 41,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/BinderInterface.zep",
        "line": 0,
        "char": 0
    }
]