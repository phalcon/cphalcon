[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator",
        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                "line": 13,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                "line": 15,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
        "line": 17,
        "char": 5
    },
    {
        "type": "class",
        "name": "PaginatorFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
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
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 22,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 22,
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
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 24,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 24,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 24,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 24,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 25,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * AdapterFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                    "line": 22,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "load",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "config",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 50,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 52,
                                    "char": 17
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 52,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "config",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 54,
                                            "char": 28
                                        },
                                        "name": "checkConfig",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 54,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 54,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 54,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 54,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 55,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 55,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 55,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 55,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
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
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 56,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 56,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 56,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 56,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 56,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 56,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 56,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 56,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 58,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 58,
                                    "char": 21
                                },
                                "name": "newInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 58,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 58,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 58,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 58,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 58,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Factory to create an instace from a Config object\n     *\n     *```php\n     * use Phalcon\\Paginator\\PaginatorFactory;\n     *\n     * $builder = $this\n     *      ->modelsManager\n     *      ->createBuilder()\n     *      ->columns(\"id, name\")\n     *      ->from(Robots::class)\n     *      ->orderBy(\"name\");\n     *\n     * $options = [\n     *     \"builder\" => $builder,\n     *     \"limit\"   => 20,\n     *     \"page\"    => 1,\n     *     \"adapter\" => \"queryBuilder\",\n     * ];\n     *\n     * $paginator = (new PaginatorFactory())->load($options);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 51,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                        "line": 51,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                    "line": 50,
                    "last-line": 63,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 64,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 64,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 64,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 66,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 68,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 68,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 68,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 68,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 68,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 70,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 70,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 70,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 70,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 70,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 70,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 70,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 70,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                        "line": 71,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                        "line": 71,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 71,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 71,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 71,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 71,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "services",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                    "line": 72,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                            "line": 72,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                        "line": 72,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                                "line": 72,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 72,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 75,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 75,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 75,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 75,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 75,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 75,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 76,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new instance of the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AbstractAdapter",
                                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                    "line": 65,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                    "line": 64,
                    "last-line": 78,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 81,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Paginator\\\\Adapter\\\\Model",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 81,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 81,
                                        "char": 64
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "nativeArray",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 82,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Paginator\\\\Adapter\\\\NativeArray",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 82,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 82,
                                        "char": 70
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "queryBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 83,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Paginator\\\\Adapter\\\\QueryBuilder",
                                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                            "line": 84,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                        "line": 84,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 84,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                            "line": 85,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
                    "line": 78,
                    "last-line": 86,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
            "line": 17,
            "char": 5
        },
        "file": "\/app\/phalcon\/Paginator\/PaginatorFactory.zep",
        "line": 17,
        "char": 5
    }
]