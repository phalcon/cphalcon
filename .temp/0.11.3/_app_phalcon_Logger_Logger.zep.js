[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger",
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Log\\LoggerInterface",
                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                "line": 13,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Log\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                "line": 14,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                "line": 16,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Exception",
                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                "line": 17,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 51,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\n *\n * This component offers logging capabilities for your application. The\n * component accepts multiple adapters, working also as a multiple logger.\n * Phalcon\\Logger implements PSR-3.\n *\n *```php\n * use Phalcon\\Logger;\n * use Phalcon\\Logger\\Adapter\\Stream;\n *\n * $adapter1 = new Stream('\/logs\/first-log.log');\n * $adapter2 = new Stream('\/remote\/second-log.log');\n * $adapter3 = new Stream('\/manager\/third-log.log');\n *\n * $logger = new Logger(\n *         'messages',\n *         [\n *             'local'   => $adapter1,\n *             'remote'  => $adapter2,\n *             'manager' => $adapter3,\n *         ]\n *     );\n *\n * \/\/ Log to all adapters\n * $logger->error('Something went wrong');\n *\n * \/\/ Log to specific adapters\n * $logger\n *         ->excludeAdapters(['manager'])\n *         ->info('This does not go to the \"manager\" logger);\n *```\n *",
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 52,
        "char": 5
    },
    {
        "type": "class",
        "name": "Logger",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "LoggerInterface",
                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                "line": 53,
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
                    "name": "adapters",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 69,
                        "char": 28
                    },
                    "docblock": "**\n     * The adapter stack\n     *\n     * @var AdapterInterface[]\n     *",
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 73,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 74,
                        "char": 22
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 80,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "excluded",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 81,
                        "char": 28
                    },
                    "docblock": "**\n     * The excluded adapters for this log process\n     *\n     * @var AdapterInterface[]\n     *",
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 88,
                    "char": 6
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 89,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "adapters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 89,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 89,
                            "char": 67
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
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 91,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 91,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 93,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 93,
                                    "char": 14
                                },
                                "name": "setAdapters",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 93,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 93,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 93,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 94,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor.\n     *\n     * @param string name     The name of the logger\n     * @param array  adapters The collection of adapters to be used for logging (default [])\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 89,
                    "last-line": 101,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addAdapter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 102,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "adapter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 102,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 102,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "adapters",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 104,
                                            "char": 32
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 104,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 104,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 106,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 106,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 107,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Add an adapter to the stack. For processing we use FIFO\n     *\n     * @param string             name    The name of the adapter\n     * @param <AdapterInterface> adapter The adapter to add to the stack\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Logger",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 103,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 103,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 103,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 102,
                    "last-line": 116,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "alert",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 117,
                            "char": 34
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 117,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 117,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 119,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 119,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ALERT",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 119,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 119,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 119,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 119,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 119,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 119,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 119,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 119,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 119,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 120,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Action must be taken immediately.\n     *\n     * Example: Entire website down, database unavailable, etc. This should\n     * trigger the SMS alerts and wake you up.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 117,
                    "last-line": 128,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "critical",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 129,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 129,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 129,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 131,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 131,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "CRITICAL",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 131,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 131,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 131,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 131,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 131,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 131,
                                        "char": 58
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 131,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 131,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 131,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Critical conditions.\n     *\n     * Example: Application component unavailable, unexpected exception.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 130,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 129,
                    "last-line": 138,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "debug",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 139,
                            "char": 34
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 139,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 139,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 141,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 141,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "DEBUG",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 141,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 141,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 141,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 141,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 141,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 141,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 141,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 141,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 141,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 142,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Detailed debug information.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 140,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 139,
                    "last-line": 149,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "error",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 150,
                            "char": 34
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 150,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 150,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 152,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 152,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ERROR",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 152,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 152,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 152,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 152,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 152,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 152,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 152,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 152,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 152,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Runtime errors that do not require immediate action but should typically\n     * be logged and monitored.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 151,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 150,
                    "last-line": 159,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "emergency",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 160,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 160,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 160,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 162,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 162,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "EMERGENCY",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 162,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 162,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 162,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 162,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 162,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 162,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 162,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 162,
                                        "char": 68
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 162,
                                "char": 69
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 163,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * System is unusable.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 161,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 160,
                    "last-line": 167,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "excludeAdapters",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "adapters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 168,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 168,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 170,
                                    "char": 17
                                },
                                {
                                    "variable": "registered",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 170,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 172,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "registered",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 172,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 172,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 172,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 172,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 179,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "adapters",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 179,
                                "char": 30
                            },
                            "value": "name",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "registered",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 180,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 180,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 180,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 180,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "excluded",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                            "line": 181,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 181,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 181,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 182,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 183,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 185,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 185,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Exclude certain adapters.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Logger",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 169,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 169,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 169,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 168,
                    "last-line": 194,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAdapter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 195,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "adapter",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 197,
                                    "char": 20
                                },
                                {
                                    "variable": "adapters",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 197,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 199,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "adapters",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 199,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 199,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 199,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 199,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 201,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 201,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 201,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 201,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 201,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 201,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 201,
                                "char": 43
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
                                                    "value": "Adapter does not exist for this logger",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 202,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 202,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 202,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 203,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 205,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "adapter",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 205,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 206,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an adapter from the stack\n     *\n     * @param string name The name of the adapter\n     *\n     * @throws <Exception>\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 196,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 196,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 196,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 195,
                    "last-line": 212,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 215,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapters",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 215,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 215,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 216,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the adapter stack array\n     *\n     * @return AdapterInterface[]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 214,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 214,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 213,
                    "last-line": 220,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 223,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 223,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 223,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 224,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the name of the logger\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 222,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 222,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 221,
                    "last-line": 232,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "info",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 233,
                            "char": 33
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 233,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 233,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 235,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 235,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "INFO",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 235,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 235,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 235,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 235,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 235,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 235,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 235,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 235,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 235,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 236,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Interesting events.\n     *\n     * Example: User logs in, SQL logs.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 234,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 233,
                    "last-line": 243,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "log",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 244,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 244,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 244,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 244,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "intLevel",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 246,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 248,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "intLevel",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 248,
                                            "char": 29
                                        },
                                        "name": "getLevelNumber",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "level",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 248,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 248,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 248,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 248,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 250,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 250,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "level",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 250,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 250,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 250,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 250,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 250,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 250,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 250,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 250,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 251,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Logs with an arbitrary level.\n     *\n     * @param mixed  level\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 245,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 244,
                    "last-line": 257,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notice",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 258,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 258,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 258,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 260,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 260,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "NOTICE",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 260,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 260,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 260,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 260,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 260,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 260,
                                        "char": 56
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 260,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 260,
                                        "char": 65
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 260,
                                "char": 66
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 261,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Normal but significant events.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 259,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 258,
                    "last-line": 269,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "removeAdapter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 270,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "adapters",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 272,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 274,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "adapters",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 274,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 274,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 274,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 274,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 276,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 276,
                                    "char": 19
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "adapters",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 276,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 276,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 276,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 276,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 276,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 276,
                                "char": 43
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
                                                    "value": "Adapter does not exist for this logger",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 277,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 277,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 277,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 278,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 280,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "adapters",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 280,
                                    "char": 23
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 280,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 280,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 282,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "adapters",
                                    "expr": {
                                        "type": "variable",
                                        "value": "adapters",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 282,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 282,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 284,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 284,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes an adapter from the stack\n     *\n     * @param string name The name of the adapter\n     *\n     * @throws <Logger\\Exception>\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Logger",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 271,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 271,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 271,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 270,
                    "last-line": 291,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAdapters",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "adapters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 292,
                            "char": 48
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
                                    "property": "adapters",
                                    "expr": {
                                        "type": "variable",
                                        "value": "adapters",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 294,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 294,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 296,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 296,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 297,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the adapters stack overriding what is already there\n     *\n     * @param array adapters An array of adapters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Logger",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 293,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 293,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 293,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 292,
                    "last-line": 306,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "warning",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 307,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 307,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 307,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 309,
                                    "char": 14
                                },
                                "name": "addMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 309,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "WARNING",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 309,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 309,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 309,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "cast",
                                            "left": "string",
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 309,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 309,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 309,
                                        "char": 57
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 309,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 309,
                                        "char": 66
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 309,
                                "char": 67
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 310,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Exceptional occurrences that are not errors.\n     *\n     * Example: Use of deprecated APIs, poor use of an API, undesirable things\n     * that are not necessarily wrong.\n     *\n     * @param string message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 308,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 307,
                    "last-line": 319,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "addMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 320,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 320,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 320,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 320,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "adapter",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 20
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 25
                                },
                                {
                                    "variable": "excluded",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 35
                                },
                                {
                                    "variable": "levelName",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 46
                                },
                                {
                                    "variable": "levels",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 54
                                },
                                {
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 60
                                },
                                {
                                    "variable": "registered",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 322,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 324,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "registered",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 324,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 324,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 324,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 324,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "excluded",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 325,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "excluded",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 325,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 325,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 325,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 327,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "registered",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 327,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 327,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 327,
                                    "char": 32
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 327,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 327,
                                "char": 36
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
                                                    "value": "No adapters specified",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 328,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 328,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 328,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 329,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 331,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "levels",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 331,
                                            "char": 27
                                        },
                                        "name": "getLevels",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 331,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 331,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 333,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "levelName",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 333,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "levels",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 333,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "level",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 333,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 333,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 333,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 333,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "levelName",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "levels",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 334,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 334,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "CUSTOM",
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 334,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 334,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 334,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 334,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 335,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 337,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "item",
                                    "expr": {
                                        "type": "new",
                                        "class": "Item",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 337,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 337,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "levelName",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 337,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 337,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "level",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 337,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 337,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "time",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 337,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 337,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "context",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 337,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 337,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 337,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 337,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 342,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "registered",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 342,
                                "char": 40
                            },
                            "key": "key",
                            "value": "adapter",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "excluded",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 343,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 343,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 343,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 343,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 343,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "adapter",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 344,
                                                    "char": 25
                                                },
                                                "name": "process",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "item",
                                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                            "line": 344,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 344,
                                                        "char": 38
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 344,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 345,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 346,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 351,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "excluded",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 351,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 351,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 353,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 353,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 354,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a message to each handler for processing\n     *\n     * @param int    level\n     * @param string message\n     *\n     * @throws <Logger\\Exception>\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 321,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 321,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 320,
                    "last-line": 358,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getLevels",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 362,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ALERT",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 362,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 362,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "alert",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 362,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 362,
                                        "char": 36
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 363,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "CRITICAL",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 363,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 363,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "critical",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 363,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 363,
                                        "char": 39
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 364,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "DEBUG",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 364,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 364,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "debug",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 364,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 364,
                                        "char": 36
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 365,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "EMERGENCY",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 365,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 365,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "emergency",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 365,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 365,
                                        "char": 40
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 366,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ERROR",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 366,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 366,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 366,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 366,
                                        "char": 36
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 367,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "INFO",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 367,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 367,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "info",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 367,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 367,
                                        "char": 35
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 368,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "NOTICE",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 368,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 368,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "notice",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 368,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 368,
                                        "char": 37
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 369,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "WARNING",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 369,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 369,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "warning",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 369,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 369,
                                        "char": 38
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 370,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "CUSTOM",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 370,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 370,
                                            "char": 29
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "custom",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 371,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 371,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 371,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 372,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of log levels with integer to string conversion\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 360,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 360,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 359,
                    "last-line": 378,
                    "char": 22
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getLevelNumber",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 379,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "levelName",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 381,
                                    "char": 22
                                },
                                {
                                    "variable": "numberLevel",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 381,
                                    "char": 35
                                },
                                {
                                    "variable": "levels",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 381,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 383,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "level",
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 383,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 383,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 383,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 383,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "levelName",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "level",
                                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                            "line": 384,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 384,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 384,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 384,
                                            "char": 46
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "levels",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_flip",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                                "line": 385,
                                                                "char": 45
                                                            },
                                                            "name": "getLevels",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                            "line": 385,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 385,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 385,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 385,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 387,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "numberLevel",
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 387,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "levels",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 387,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "levelName",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 387,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 387,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 387,
                                        "char": 53
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "numberLevel",
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 388,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 389,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 390,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "is_numeric",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "level",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 390,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 390,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                        "line": 390,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "levels",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                            "line": 391,
                                                            "char": 31
                                                        },
                                                        "name": "getLevels",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 391,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 391,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 393,
                                            "char": 14
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "numberLevel",
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 393,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "levels",
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 393,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "level",
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 393,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 393,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                "line": 393,
                                                "char": 49
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "numberLevel",
                                                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                        "line": 394,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                                    "line": 395,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                            "line": 396,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 398,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 398,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 398,
                                    "char": 28
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "CUSTOM",
                                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                    "line": 398,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 398,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Logger\/Logger.zep",
                            "line": 399,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Converts the level from string\/word to an integer\n     *\n     * @param string|int level\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Logger.zep",
                                "line": 380,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 380,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 379,
                    "last-line": 400,
                    "char": 20
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "ALERT",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 54,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 55,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRITICAL",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 55,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 56,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CUSTOM",
                    "default": {
                        "type": "int",
                        "value": "8",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 56,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 57,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "DEBUG",
                    "default": {
                        "type": "int",
                        "value": "7",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 57,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 58,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "EMERGENCY",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 58,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 59,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "ERROR",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 59,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 60,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "INFO",
                    "default": {
                        "type": "int",
                        "value": "6",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 60,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 61,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOTICE",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 61,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 62,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "WARNING",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Logger\/Logger.zep",
                        "line": 62,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Logger\/Logger.zep",
                    "line": 68,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Logger.zep",
            "line": 52,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Logger.zep",
        "line": 52,
        "char": 5
    }
]