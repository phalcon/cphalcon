[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\AdapterFactory",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                "line": 15,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 34,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\\Apcu\n *\n * Stores model meta-data in the APCu cache. Data will erased if the web server is restarted\n *\n * By default meta-data is stored for 48 hours (172800 seconds)\n *\n * You can query the meta-data by printing apcu_fetch('$PMM$') or apcu_fetch('$PMM$my-app-id')\n *\n *```php\n * $metaData = new \\Phalcon\\Mvc\\Model\\MetaData\\Apcu(\n *     [\n *         \"prefix\"   => \"my-app-id\",\n *         \"lifetime\" => 86400,\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 35,
        "char": 5
    },
    {
        "type": "class",
        "name": "Apcu",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                "line": 42,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                            "line": 42,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                "line": 42,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                            "line": 42,
                            "char": 80
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                            "line": 44,
                                            "char": 27
                                        }
                                    ],
                                    "expr": {
                                        "type": "string",
                                        "value": "ph-mm-apcu-",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                        "line": 44,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                    "line": 44,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                            "line": 45,
                                            "char": 29
                                        }
                                    ],
                                    "expr": {
                                        "type": "int",
                                        "value": "172800",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                        "line": 45,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                    "line": 45,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                            "line": 46,
                                            "char": 43
                                        },
                                        "name": "newInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "apcu",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                                    "line": 46,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                                "line": 46,
                                                "char": 60
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                                    "line": 46,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                                "line": 46,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                        "line": 46,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                                    "line": 46,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                            "line": 47,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\MetaData\\Apcu constructor\n     *\n     * @param array options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                        "line": 43,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
                    "line": 42,
                    "last-line": 48,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
            "line": 35,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Apcu.zep",
        "line": 35,
        "char": 5
    }
]