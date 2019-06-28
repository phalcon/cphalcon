[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session\\Adapter",
        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\AdapterFactory",
                "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                "line": 13,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Session\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Session\\Adapter\\Libmemcached\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Libmemcached",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                "line": 24,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                            "line": 24,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                "line": 24,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                            "line": 24,
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
                                            "value": "prefix",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                            "line": 26,
                                            "char": 27
                                        }
                                    ],
                                    "expr": {
                                        "type": "string",
                                        "value": "sess-memc-",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                        "line": 26,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                    "line": 26,
                                    "char": 41
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
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                            "line": 27,
                                            "char": 41
                                        },
                                        "name": "newInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "libmemcached",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                                    "line": 27,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                                "line": 27,
                                                "char": 66
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                                    "line": 27,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                                "line": 27,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                        "line": 27,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                                    "line": 27,
                                    "char": 76
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                            "line": 28,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                        "line": 25,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
                    "line": 24,
                    "last-line": 29,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Session\/Adapter\/Libmemcached.zep",
        "line": 19,
        "char": 5
    }
]