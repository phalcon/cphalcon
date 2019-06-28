[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\AdapterFactory",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\\Libmemcached\n *\n * Stores model meta-data in the Memcache.\n *\n * By default meta-data is stored for 48 hours (172800 seconds)\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "Libmemcached",
        "abstract": 0,
        "final": 0,
        "extends": "MetaData",
        "definition": {
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
                            "name": "factory",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterFactory",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                "line": 32,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                            "line": 32,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                "line": 32,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                            "line": 32,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "persistentId",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                            "line": 34,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 34,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 34,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "persistentId",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 34,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 34,
                                                "char": 67
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "ph-mm-mcid-",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 34,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 34,
                                                "char": 80
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                        "line": 34,
                                        "char": 81
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                    "line": 34,
                                    "char": 81
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "prefix",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                            "line": 35,
                                            "char": 27
                                        }
                                    ],
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 35,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 35,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 35,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 35,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "ph-mm-memc-",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 35,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 35,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                        "line": 35,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                    "line": 35,
                                    "char": 75
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "lifetime",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                            "line": 36,
                                            "char": 29
                                        }
                                    ],
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 36,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 36,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "lifetime",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 36,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 36,
                                                "char": 63
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "172800",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 36,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 36,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                        "line": 36,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                    "line": 36,
                                    "char": 72
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "adapter",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "factory",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                            "line": 37,
                                            "char": 47
                                        },
                                        "name": "newInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "libmemcached",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 37,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 37,
                                                "char": 72
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                    "line": 37,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                                "line": 37,
                                                "char": 81
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                        "line": 37,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                    "line": 37,
                                    "char": 82
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                            "line": 38,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\MetaData\\Libmemcached constructor\n     *\n     * @param array options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                    "line": 32,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                        "line": 45,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                        "line": 45,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                    "line": 45,
                                    "char": 23
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                "line": 45,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                            "line": 47,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "reset",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                                "line": 47,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Flush Memcache data and resets internal meta-data in order to regenerate it\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                        "line": 44,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
                    "line": 43,
                    "last-line": 49,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Libmemcached.zep",
        "line": 25,
        "char": 5
    }
]