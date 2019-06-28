[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\AdapterFactory",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                "line": 14,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
        "line": 36,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\\Redis\n *\n * Stores model meta-data in the Redis.\n *\n * By default meta-data is stored for 48 hours (172800 seconds)\n *\n *```php\n * use Phalcon\\Mvc\\Model\\MetaData\\Redis;\n *\n * $metaData = new Redis(\n *     [\n *         \"host\"       => \"127.0.0.1\",\n *         \"port\"       => 6379,\n *         \"persistent\" => 0,\n *         \"lifetime\"   => 172800,\n *         \"index\"      => 2,\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
        "line": 37,
        "char": 5
    },
    {
        "type": "class",
        "name": "Redis",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                "line": 44,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                            "line": 44,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                "line": 44,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                            "line": 44,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                            "line": 46,
                                            "char": 27
                                        }
                                    ],
                                    "expr": {
                                        "type": "string",
                                        "value": "ph-mm-reds-",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                        "line": 46,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                    "line": 46,
                                    "char": 44
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "lifetime",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                            "line": 47,
                                            "char": 29
                                        }
                                    ],
                                    "expr": {
                                        "type": "int",
                                        "value": "172800",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                        "line": 47,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                    "line": 47,
                                    "char": 39
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                            "line": 48,
                                            "char": 43
                                        },
                                        "name": "newInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "redis",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                                    "line": 48,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                                "line": 48,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                                    "line": 48,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                                "line": 48,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                        "line": 48,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                    "line": 48,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\MetaData\\Redis constructor\n     *\n     * @param array options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                        "line": 45,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                    "line": 44,
                    "last-line": 53,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                        "line": 56,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                        "line": 56,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                    "line": 56,
                                    "char": 23
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                "line": 56,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                            "line": 58,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                                "line": 58,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Flush Redis data and resets internal meta-data in order to regenerate it\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                        "line": 55,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
                    "line": 54,
                    "last-line": 60,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
            "line": 37,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Redis.zep",
        "line": 37,
        "char": 5
    }
]