[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cache",
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                "line": 13,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Exception\\Exception",
                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                "line": 15,
                "char": 53
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\SimpleCache\\CacheInterface",
                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                "line": 16,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Traversable",
                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                "line": 17,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This component offers caching capabilities for your application.\n * Phalcon\\Cache implements PSR-16.\n *",
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "Cache",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "CacheInterface",
                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                "line": 24,
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
                    "name": "adapter",
                    "docblock": "**\n     * The adapter\n     *\n     * @var AdapterInterface\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 30,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 36,
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
                            "name": "adapter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 37,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 37,
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
                                    "property": "adapter",
                                    "expr": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 39,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 39,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor.\n     *\n     * @param AdapterInterface  adapter The cache adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 38,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 37,
                    "last-line": 46,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 49,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 49,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 49,
                                    "char": 30
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 49,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 50,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Wipes clean the entire cache's keys.\n     *\n     * @return bool True on success and false on failure.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 48,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 48,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 47,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 62,
                            "char": 35
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
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 64,
                                    "char": 14
                                },
                                "name": "checkKey",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 64,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 64,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 64,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 66,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 66,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 66,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 66,
                                    "char": 30
                                },
                                "name": "delete",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 66,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 66,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 66,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Delete an item from the cache by its unique key.\n     *\n     * @param string $key The unique cache key of the item to delete.\n     *\n     * @return bool True if the item was successfully removed. False if there was an error.\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if the $key string is not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 62,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "deleteMultiple",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "keys",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 80,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 82,
                                    "char": 16
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 82,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 84,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 84,
                                    "char": 14
                                },
                                "name": "checkKeys",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "keys",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 84,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 84,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 84,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 86,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 86,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 86,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 88,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "keys",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 88,
                                "char": 25
                            },
                            "value": "key",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 89,
                                                    "char": 22
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "adapter",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 89,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 89,
                                                "char": 31
                                            },
                                            "name": "delete",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 89,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 89,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 89,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 89,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "result",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 90,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 90,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 91,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 94,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 94,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deletes multiple cache items in a single operation.\n     *\n     * @param iterable $keys A list of string-based keys to be deleted.\n     *\n     * @return bool True if the items were successfully removed. False if there was an error.\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if $keys is neither an array nor a Traversable,\n     *   or if any of the $keys are not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 81,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 80,
                    "last-line": 107,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 108,
                            "char": 32
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 108,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 108,
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
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 110,
                                    "char": 14
                                },
                                "name": "checkKey",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 110,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 110,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 110,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 112,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 112,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 112,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 112,
                                    "char": 30
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 112,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 112,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 112,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 112,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 112,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 113,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fetches a value from the cache.\n     *\n     * @param string $key     The unique key of this item in the cache.\n     * @param mixed  $default Default value to return if the key does not exist.\n     *\n     * @return mixed The value of the item from the cache, or $default in case of cache miss.\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if the $key string is not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 108,
                    "last-line": 126,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMultiple",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "keys",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 127,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 127,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 127,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 129,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 130,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "results",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 130,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 132,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 132,
                                    "char": 14
                                },
                                "name": "checkKeys",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "keys",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 132,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 132,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 132,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 134,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "results",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 134,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 134,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 135,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "keys",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 135,
                                "char": 29
                            },
                            "value": "element",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "results",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "element",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 136,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 136,
                                                    "char": 41
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "element",
                                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                            "line": 136,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 136,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "defaultValue",
                                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                            "line": 136,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 136,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 136,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 136,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 137,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 139,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "results",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 139,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 140,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Obtains multiple cache items by their unique keys.\n     *\n     * @param iterable $keys    A list of keys that can obtained in a single operation.\n     * @param mixed    $default Default value to return for keys that do not exist.\n     *\n     * @return iterable A list of key => value pairs. Cache keys that do not exist or are stale will have $default as value.\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if $keys is neither an array nor a Traversable,\n     *   or if any of the $keys are not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 128,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 128,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 127,
                    "last-line": 151,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 152,
                            "char": 32
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
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 154,
                                    "char": 14
                                },
                                "name": "checkKey",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 154,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 154,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 154,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 156,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 156,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 156,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 156,
                                    "char": 30
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 156,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 156,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 156,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 157,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Determines whether an item is present in the cache.\n     *\n     * @param string $key The cache item key.\n     *\n     * @return bool\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if the $key string is not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 153,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 153,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 152,
                    "last-line": 172,
                    "char": 19
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
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 173,
                            "char": 32
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 173,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "ttl",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 173,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 173,
                            "char": 59
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
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 175,
                                    "char": 14
                                },
                                "name": "checkKey",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 175,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 175,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 175,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 177,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 177,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 177,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 177,
                                    "char": 30
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 177,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 177,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 177,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 177,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ttl",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 177,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 177,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 177,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Persists data in the cache, uniquely referenced by a key with an optional expiration TTL time.\n     *\n     * @param string                 $key   The key of the item to store.\n     * @param mixed                  $value The value of the item to store. Must be serializable.\n     * @param null|int|\\DateInterval $ttl   Optional. The TTL value of this item. If no value is sent and\n     *                                      the driver supports TTL then the library may set a default value\n     *                                      for it or let the driver take care of that.\n     *\n     * @return bool True on success and false on failure.\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if the $key string is not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 174,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 174,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 173,
                    "last-line": 193,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMultiple",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 194,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "ttl",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 194,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 194,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 196,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 196,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 197,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 197,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 199,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 199,
                                    "char": 14
                                },
                                "name": "checkKeys",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "values",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 199,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 199,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 199,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 201,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 201,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 201,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 202,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "values",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 202,
                                "char": 34
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 203,
                                                "char": 22
                                            },
                                            "name": "set",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 203,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 203,
                                                    "char": 30
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 203,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 203,
                                                    "char": 37
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ttl",
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 203,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 203,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 203,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 203,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "result",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                        "line": 204,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 204,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 205,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 206,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 208,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 208,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 209,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Persists a set of key => value pairs in the cache, with an optional TTL.\n     *\n     * @param iterable               $values A list of key => value pairs for a multiple-set operation.\n     * @param null|int|\\DateInterval $ttl    Optional. The TTL value of this item. If no value is sent and\n     *                                       the driver supports TTL then the library may set a default value\n     *                                       for it or let the driver take care of that.\n     *\n     * @return bool True on success and false on failure.\n     *\n     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException\n     *   MUST be thrown if $values is neither an array nor a Traversable,\n     *   or if any of the $values are not a legal value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 195,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 195,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 194,
                    "last-line": 213,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 214,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 216,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 216,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 216,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 218,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_match",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\/[^A-Za-z0-9-_]\/",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 218,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 218,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 218,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 218,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 218,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The key contains invalid characters",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 221,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 221,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 221,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 222,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 223,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the key. If it contains invalid characters an exception is thrown\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 215,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 214,
                    "last-line": 227,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkKeys",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "keys",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 228,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "keys",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 230,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 230,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 230,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 230,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "keys",
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 230,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "Traversable",
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 230,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                            "line": 230,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 230,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 230,
                                    "char": 68
                                },
                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                "line": 230,
                                "char": 68
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The keys need to be an array or instance of Traversable",
                                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                    "line": 233,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                                "line": 233,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                        "line": 233,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                                    "line": 234,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/Cache.zep",
                            "line": 235,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the key. If it contains invalid characters an exception is thrown\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cache\/Cache.zep",
                        "line": 229,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/Cache.zep",
                    "line": 228,
                    "last-line": 236,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Cache\/Cache.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Cache\/Cache.zep",
        "line": 23,
        "char": 5
    }
]