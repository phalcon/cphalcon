[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets",
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 14,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Collection",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 15,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Exception",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 16,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset\\Js",
                "alias": "AssetJs",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 17,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset\\Css",
                "alias": "AssetCss",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Inline\\Css",
                "alias": "InlineCss",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 19,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Inline\\Js",
                "alias": "InlineJs",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 20,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 21,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 22,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 28,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Assets\\Manager\n *\n * Manages collections of CSS\/Javascript assets\n *",
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 29,
        "char": 5
    },
    {
        "type": "class",
        "name": "Manager",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                "line": 30,
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
                    "name": "collections",
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "docblock": "**\n     * @var DiInterface\n     *",
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 41,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "docblock": "**\n     * Options configure\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "implicitOutput",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 47,
                        "char": 36
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 51,
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
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 52,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 52,
                            "char": 51
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
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 54,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 54,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Assets\\Manager constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 53,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 52,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addAsset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "asset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Asset",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 66,
                                "char": 42
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 66,
                            "char": 43
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
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 71,
                                    "char": 14
                                },
                                "name": "addAssetByType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "asset",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 72,
                                                "char": 19
                                            },
                                            "name": "getType",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 72,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 72,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "asset",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 74,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 74,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 74,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 76,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 76,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a raw asset to the manager\n     *\n     *```php\n     * $assets->addAsset(\n     *     new Phalcon\\Assets\\Asset(\"css\", \"css\/style.css\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 67,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 66,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addAssetByType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 89,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "asset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Asset",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 89,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 89,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 91,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 93,
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
                                        "value": "collection",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 93,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 93,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "collections",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 93,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 93,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 93,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 93,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 93,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 93,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "new",
                                                "class": "Collection",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 94,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 94,
                                            "char": 59
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "collections",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 95,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 95,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 95,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 101,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 101,
                                    "char": 20
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "asset",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 101,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 101,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 101,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 103,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 103,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 104,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a asset by its type\n     *\n     *```php\n     * $assets->addAssetByType(\n     *     \"css\",\n     *     new \\Phalcon\\Assets\\Asset\\Css(\"css\/style.css\")\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 90,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 90,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 89,
                    "last-line": 113,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addCss",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 115,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 116,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 116,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 117,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 117,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 118,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 118,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "version",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 119,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 119,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "autoVersion",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 121,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 121,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 123,
                                    "char": 14
                                },
                                "name": "addAssetByType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "css",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 124,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 124,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "AssetCss",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 125,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 125,
                                                    "char": 30
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "local",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 125,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 125,
                                                    "char": 37
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 125,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 125,
                                                    "char": 45
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 125,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 125,
                                                    "char": 57
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 125,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 125,
                                                    "char": 66
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "autoVersion",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 125,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 125,
                                                    "char": 79
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 126,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 126,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 126,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 128,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 128,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Adds a Css asset to the 'css' collection\n    *\n    *```php\n    * $assets->addCss(\"css\/bootstrap.css\");\n    * $assets->addCss(\"http:\/\/bootstrap.my-cdn.com\/style.css\", false);\n    *```\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 122,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 122,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 122,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 114,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addInlineCode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Inline",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 134,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 134,
                            "char": 48
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
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 139,
                                    "char": 14
                                },
                                "name": "addInlineCodeByType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "code",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 139,
                                                "char": 40
                                            },
                                            "name": "getType",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 139,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 139,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "code",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 139,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 139,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 139,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 141,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 141,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 142,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a raw inline code to the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 135,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 134,
                    "last-line": 146,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addInlineCodeByType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 147,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Inline",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 147,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 147,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 149,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 151,
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
                                        "value": "collection",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 151,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 151,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "collections",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 151,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 151,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 151,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 151,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 151,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 151,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "new",
                                                "class": "Collection",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 152,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 152,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 153,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "collections",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 153,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 153,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 153,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 154,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 159,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 159,
                                    "char": 20
                                },
                                "name": "addInline",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "code",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 159,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 159,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 159,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 161,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 161,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an inline code by its type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 148,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 148,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 148,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 147,
                    "last-line": 166,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addInlineCss",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 167,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 167,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 167,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 167,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 167,
                            "char": 86
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
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 169,
                                    "char": 14
                                },
                                "name": "addInlineCodeByType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "css",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 170,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 170,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "InlineCss",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "content",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 171,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 171,
                                                    "char": 34
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 171,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 171,
                                                    "char": 42
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 171,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 171,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 172,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 172,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 172,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 174,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 174,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an inline Css to the 'css' collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 168,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 168,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 168,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 167,
                    "last-line": 179,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addInlineJs",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 180,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 180,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 180,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 180,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 180,
                            "char": 81
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
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 182,
                                    "char": 14
                                },
                                "name": "addInlineCodeByType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "js",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 183,
                                            "char": 15
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 183,
                                        "char": 15
                                    },
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "InlineJs",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "content",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 184,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 184,
                                                    "char": 33
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 184,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 184,
                                                    "char": 41
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 184,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 184,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 185,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 185,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 185,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 187,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 187,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 188,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an inline javascript to the 'js' collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 181,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 181,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 181,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 180,
                    "last-line": 197,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addJs",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 199,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 200,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 200,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 201,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 201,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 202,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 202,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "version",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 203,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 203,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "autoVersion",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 205,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 205,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 207,
                                    "char": 14
                                },
                                "name": "addAssetByType",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "js",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 208,
                                            "char": 15
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 208,
                                        "char": 15
                                    },
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "AssetJs",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 209,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 209,
                                                    "char": 29
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "local",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 209,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 209,
                                                    "char": 36
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 209,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 209,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 209,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 209,
                                                    "char": 56
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 209,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 209,
                                                    "char": 65
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "autoVersion",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 209,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 209,
                                                    "char": 78
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 210,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 210,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 210,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 212,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 212,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 213,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a javascript asset to the 'js' collection\n     *\n     *```php\n     * $assets->addJs(\"scripts\/jquery.js\");\n     * $assets->addJs(\"http:\/\/jquery.my-cdn.com\/jquery.js\", false);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 206,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 206,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 206,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 198,
                    "last-line": 217,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "collection",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 218,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 220,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 222,
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
                                        "value": "collection",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 222,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 222,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "collections",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 222,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 222,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 222,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 222,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 222,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 222,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "new",
                                                "class": "Collection",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 223,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 223,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 224,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "collections",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 224,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 224,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 224,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 225,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 227,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 227,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 228,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates\/Returns a collection of assets\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 219,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 219,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 219,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 218,
                    "last-line": 232,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "collectionAssetsByType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "assets",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 233,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 233,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "asset",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 235,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 236,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "filtered",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 236,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 236,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 238,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "assets",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 238,
                                "char": 29
                            },
                            "value": "asset",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "asset",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 239,
                                                "char": 22
                                            },
                                            "name": "getType",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 239,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 239,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 239,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "filtered",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "asset",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 240,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 240,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 241,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 242,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 244,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "filtered",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 244,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 245,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates\/Returns a collection of assets by type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 234,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 234,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 233,
                    "last-line": 256,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "exists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 257,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 259,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "collections",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 259,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 259,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 259,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 259,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 259,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 260,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true or false if collection exists.\n     *\n     * ```php\n     * if ($assets->exists(\"jsHeader\")) {\n     *     \/\/ \\Phalcon\\Assets\\Collection\n     *     $collection = $assets->get(\"jsHeader\");\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 258,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 258,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 257,
                    "last-line": 268,
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
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 269,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 271,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 273,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 273,
                                            "char": 62
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 273,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "collections",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 273,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 273,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 273,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 273,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 273,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 273,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 273,
                                "char": 62
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
                                                    "value": "The collection does not exist in the manager",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 274,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 274,
                                                "char": 77
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 274,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 275,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 277,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 277,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 278,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a collection by its id.\n     *\n     * ```php\n     * $scripts = $assets->get(\"js\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 270,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 270,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 270,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 269,
                    "last-line": 282,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCollections",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 285,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "collections",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 285,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 285,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 286,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns existing collections in the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 284,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 284,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 284,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 283,
                    "last-line": 290,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCss",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 293,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 299,
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
                                        "value": "collection",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 299,
                                        "char": 54
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 299,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "collections",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 299,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 299,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "css",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 299,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 299,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 299,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 299,
                                "char": 54
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 300,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 301,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 303,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 303,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 304,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the CSS collection of assets\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 292,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 292,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 292,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 291,
                    "last-line": 308,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 311,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 311,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 311,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 312,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 310,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 310,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 310,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 309,
                    "last-line": 316,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getJs",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 319,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 325,
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
                                        "value": "collection",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 325,
                                        "char": 53
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 325,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "collections",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 325,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 325,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "js",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 325,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 325,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 325,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 325,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 326,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 327,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 329,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 329,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 330,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the CSS collection of assets\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 318,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 318,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 318,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 317,
                    "last-line": 334,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 337,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 337,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 337,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 338,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the manager options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 336,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 336,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 335,
                    "last-line": 345,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "output",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 346,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 346,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "callback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 346,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 346,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "output",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 348,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 349,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "asset",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 349,
                                    "char": 18
                                },
                                {
                                    "variable": "assets",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 349,
                                    "char": 26
                                },
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 349,
                                    "char": 38
                                },
                                {
                                    "variable": "autoVersion",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 349,
                                    "char": 51
                                },
                                {
                                    "variable": "collectionSourcePath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 349,
                                    "char": 73
                                },
                                {
                                    "variable": "collectionTargetPath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 350,
                                    "char": 33
                                },
                                {
                                    "variable": "completeSourcePath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 350,
                                    "char": 53
                                },
                                {
                                    "variable": "completeTargetPath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 350,
                                    "char": 73
                                },
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 351,
                                    "char": 20
                                },
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 351,
                                    "char": 28
                                },
                                {
                                    "variable": "filters",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 351,
                                    "char": 37
                                },
                                {
                                    "variable": "filteredContent",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 351,
                                    "char": 54
                                },
                                {
                                    "variable": "filteredJoinedContent",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 351,
                                    "char": 77
                                },
                                {
                                    "variable": "filterNeeded",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 352,
                                    "char": 25
                                },
                                {
                                    "variable": "html",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 352,
                                    "char": 31
                                },
                                {
                                    "variable": "join",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 352,
                                    "char": 37
                                },
                                {
                                    "variable": "local",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 352,
                                    "char": 44
                                },
                                {
                                    "variable": "modificationTime",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 352,
                                    "char": 62
                                },
                                {
                                    "variable": "mustFilter",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 352,
                                    "char": 74
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 353,
                                    "char": 20
                                },
                                {
                                    "variable": "parameters",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 353,
                                    "char": 32
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 353,
                                    "char": 38
                                },
                                {
                                    "variable": "prefixedPath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 353,
                                    "char": 52
                                },
                                {
                                    "variable": "sourceBasePath",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 353,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 353,
                                    "char": 75
                                },
                                {
                                    "variable": "sourcePath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 354,
                                    "char": 23
                                },
                                {
                                    "variable": "targetBasePath",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 354,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 354,
                                    "char": 47
                                },
                                {
                                    "variable": "targetPath",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 354,
                                    "char": 59
                                },
                                {
                                    "variable": "targetUri",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 354,
                                    "char": 70
                                },
                                {
                                    "variable": "typeCss",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 354,
                                    "char": 79
                                },
                                {
                                    "variable": "useImplicitOutput",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 355,
                                    "char": 30
                                },
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 355,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 357,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "useImplicitOutput",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 357,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "implicitOutput",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 357,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 357,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 357,
                                    "char": 53
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "output",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 358,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 358,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 363,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "assets",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 363,
                                            "char": 27
                                        },
                                        "name": "collectionAssetsByType",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "collection",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 364,
                                                        "char": 24
                                                    },
                                                    "name": "getAssets",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 364,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 364,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 366,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 366,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 366,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 366,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 371,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filters",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 371,
                                            "char": 34
                                        },
                                        "name": "getFilters",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 371,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 371,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "typeCss",
                                    "expr": {
                                        "type": "string",
                                        "value": "css",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 372,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 372,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 377,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filters",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 377,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 377,
                                        "char": 25
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 377,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "options",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 378,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 378,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 378,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 378,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 383,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 383,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 383,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 383,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 383,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "fetch",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "sourceBasePath",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 388,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 388,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "sourceBasePath",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 388,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 388,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 388,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 394,
                                            "char": 21
                                        },
                                        {
                                            "type": "fetch",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "targetBasePath",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 394,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 394,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "targetBasePath",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 394,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 394,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 394,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 395,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 400,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionSourcePath",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 400,
                                                    "char": 51
                                                },
                                                "name": "getSourcePath",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 400,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 400,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 405,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "collectionSourcePath",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 405,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeSourcePath",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "sourceBasePath",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 406,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "collectionSourcePath",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 406,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 406,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 406,
                                                    "char": 79
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 407,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeSourcePath",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "sourceBasePath",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 408,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 408,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 409,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 414,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionTargetPath",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 414,
                                                    "char": 51
                                                },
                                                "name": "getTargetPath",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 414,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 414,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 419,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "collectionTargetPath",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 419,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeTargetPath",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "targetBasePath",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 420,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "collectionTargetPath",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 420,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 420,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 420,
                                                    "char": 79
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 421,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeTargetPath",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "targetBasePath",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 422,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 422,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 423,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 428,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "filteredJoinedContent",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 428,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 428,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 433,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "join",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 433,
                                                    "char": 35
                                                },
                                                "name": "getJoin",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 433,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 433,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 438,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "join",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 438,
                                        "char": 21
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "completeTargetPath",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 442,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 442,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 442,
                                                "char": 49
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
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "Path '",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 444,
                                                                            "char": 32
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "completeTargetPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 444,
                                                                            "char": 53
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 444,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' is not a valid target path (1)",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 445,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 445,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 445,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 445,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 446,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 448,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "is_dir",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "completeTargetPath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 448,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 448,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 448,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 448,
                                                "char": 56
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
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "Path '",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 450,
                                                                            "char": 32
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "completeTargetPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 450,
                                                                            "char": 53
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 450,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' is not a valid target path (2), is dir.",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 451,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 451,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 451,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 451,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 452,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 453,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 454,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 459,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "assets",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 459,
                                "char": 29
                            },
                            "value": "asset",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "filterNeeded",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 460,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 460,
                                            "char": 37
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "type",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "asset",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 461,
                                                    "char": 38
                                                },
                                                "name": "getType",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 461,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 461,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 466,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "local",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "asset",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 466,
                                                    "char": 31
                                                },
                                                "name": "getLocal",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 466,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 466,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 472,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filters",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 472,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 472,
                                                "char": 29
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 472,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 473,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "sourcePath",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "asset",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 477,
                                                                    "char": 44
                                                                },
                                                                "name": "getRealSourcePath",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "completeSourcePath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 479,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 479,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 479,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 479,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 484,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "sourcePath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 484,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 484,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 484,
                                                        "char": 45
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "sourcePath",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "asset",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 485,
                                                                            "char": 48
                                                                        },
                                                                        "name": "getPath",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 485,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 485,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 487,
                                                            "char": 29
                                                        },
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Exception",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Asset '",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 488,
                                                                                    "char": 37
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "sourcePath",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 488,
                                                                                    "char": 50
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 488,
                                                                                "char": 50
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' does not have a valid source path",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 489,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 489,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 489,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 489,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 490,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 491,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "sourcePath",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "asset",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 495,
                                                                    "char": 44
                                                                },
                                                                "name": "getPath",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 495,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 495,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 500,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "filterNeeded",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 500,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 500,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 501,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 507,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "targetPath",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 507,
                                                            "char": 40
                                                        },
                                                        "name": "getRealTargetPath",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "completeTargetPath",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 507,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 507,
                                                                "char": 77
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 507,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 507,
                                                    "char": 78
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 512,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "targetPath",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 512,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 512,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 512,
                                                "char": 41
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
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "Asset '",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 514,
                                                                            "char": 33
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "sourcePath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 514,
                                                                            "char": 46
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 514,
                                                                        "char": 46
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' does not have a valid target path",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 515,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 515,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 515,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 515,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 516,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 518,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 518,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "targetPath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 522,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "sourcePath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 522,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 522,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 522,
                                                        "char": 58
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
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Asset '",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 524,
                                                                                    "char": 37
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "targetPath",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 524,
                                                                                    "char": 50
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 524,
                                                                                "char": 50
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' have the same source and target paths",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 525,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 525,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 525,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 525,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 526,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 528,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "file_exists",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "targetPath",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 528,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 528,
                                                                "char": 46
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 528,
                                                        "char": 48
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "compare_mtime",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "targetPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 529,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 529,
                                                                        "char": 52
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "sourcePath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 529,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 529,
                                                                        "char": 64
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 529,
                                                                "char": 66
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "filterNeeded",
                                                                            "expr": {
                                                                                "type": "bool",
                                                                                "value": "true",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 530,
                                                                                "char": 52
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 530,
                                                                            "char": 52
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 531,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 532,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "filterNeeded",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 533,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 533,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 534,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 535,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 536,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "path",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 540,
                                                            "char": 42
                                                        },
                                                        "name": "getRealTargetUri",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 540,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 540,
                                                    "char": 61
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "prefixedPath",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 541,
                                                            "char": 41
                                                        },
                                                        "name": "getPrefixedPath",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 541,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 541,
                                                                "char": 68
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "path",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 541,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 541,
                                                                "char": 74
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 541,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 541,
                                                    "char": 75
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 543,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 543,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 543,
                                                            "char": 35
                                                        },
                                                        "name": "getVersion",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 543,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 543,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "asset",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 543,
                                                        "char": 58
                                                    },
                                                    "name": "isAutoVersion",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 543,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 543,
                                                "char": 75
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "version",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 544,
                                                                    "char": 35
                                                                },
                                                                "name": "getVersion",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 544,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 544,
                                                            "char": 48
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "autoVersion",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 545,
                                                                    "char": 35
                                                                },
                                                                "name": "isAutoVersion",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 545,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 545,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 547,
                                                    "char": 10
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "autoVersion",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 547,
                                                            "char": 25
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "local",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 547,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 547,
                                                        "char": 33
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "modificationTime",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "filemtime",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "asset",
                                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                        "line": 548,
                                                                                        "char": 52
                                                                                    },
                                                                                    "name": "getRealSourcePath",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 548,
                                                                                    "char": 72
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 548,
                                                                                "char": 72
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 548,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 548,
                                                                    "char": 73
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "version",
                                                                    "expr": {
                                                                        "type": "ternary",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "version",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 549,
                                                                            "char": 44
                                                                        },
                                                                        "right": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "version",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 549,
                                                                                    "char": 54
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": ".",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 549,
                                                                                    "char": 58
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 549,
                                                                                "char": 58
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "modificationTime",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 549,
                                                                                "char": 77
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 549,
                                                                            "char": 77
                                                                        },
                                                                        "extra": {
                                                                            "type": "variable",
                                                                            "value": "modificationTime",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 549,
                                                                            "char": 95
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 549,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 549,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 550,
                                                            "char": 9
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 552,
                                                    "char": 7
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 552,
                                                        "char": 17
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "prefixedPath",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "prefixedPath",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 553,
                                                                                "char": 39
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "?ver=",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 553,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 553,
                                                                            "char": 47
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "version",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 553,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 553,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 553,
                                                                    "char": 56
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 554,
                                                            "char": 6
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 555,
                                                    "char": 5
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 560,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "attributes",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 560,
                                                            "char": 40
                                                        },
                                                        "name": "getAttributes",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 560,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 560,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 565,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 565,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 565,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 565,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 565,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "attributes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 566,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "prefixedPath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 566,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 566,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 567,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parameters",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "attributes",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 567,
                                                                            "char": 49
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 567,
                                                                        "char": 49
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 567,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 567,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 568,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parameters",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "prefixedPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 569,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 569,
                                                                        "char": 51
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 569,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 569,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 570,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 571,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "parameters",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "local",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 571,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 571,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 576,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "callback",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 576,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 576,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "parameters",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 576,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 576,
                                                                "char": 69
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 576,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 576,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 581,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "useImplicitOutput",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 581,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 581,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 581,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "echo",
                                                    "expressions": [
                                                        {
                                                            "type": "variable",
                                                            "value": "html",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 582,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 583,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "output",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "html",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 584,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 584,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 585,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 587,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 588,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 590,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "filterNeeded",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 590,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 590,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 590,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "content",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 594,
                                                            "char": 37
                                                        },
                                                        "name": "getContent",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "completeSourcePath",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 594,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 594,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 594,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 594,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 599,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "mustFilter",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 599,
                                                            "char": 40
                                                        },
                                                        "name": "getFilter",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 599,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 599,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 604,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "mustFilter",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 604,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 604,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 604,
                                                "char": 39
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "filters",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 605,
                                                        "char": 43
                                                    },
                                                    "value": "filter",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "unlikely",
                                                                "left": {
                                                                    "type": "not-equals",
                                                                    "left": {
                                                                        "type": "typeof",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "filter",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 609,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 609,
                                                                        "char": 52
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "object",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 609,
                                                                        "char": 61
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 609,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 609,
                                                                "char": 61
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
                                                                                    "value": "Filter is invalid",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 610,
                                                                                    "char": 66
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 610,
                                                                                "char": 66
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 610,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 611,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 617,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "filteredContent",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "filter",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 617,
                                                                            "char": 54
                                                                        },
                                                                        "name": "filter",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "content",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 617,
                                                                                    "char": 69
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 617,
                                                                                "char": 69
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 617,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 617,
                                                                    "char": 70
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "content",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "filteredContent",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 618,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 618,
                                                                    "char": 62
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 619,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 624,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "join",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 624,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 624,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 624,
                                                        "char": 37
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 625,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "typeCss",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 625,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 625,
                                                                "char": 44
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "concat-assign",
                                                                            "variable": "filteredJoinedContent",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "filteredContent",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 626,
                                                                                "char": 72
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 626,
                                                                            "char": 72
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 627,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "concat-assign",
                                                                            "variable": "filteredJoinedContent",
                                                                            "expr": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "filteredContent",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 628,
                                                                                    "char": 73
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": ";",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 628,
                                                                                    "char": 76
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 628,
                                                                                "char": 76
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 628,
                                                                            "char": 76
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 629,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 630,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 631,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "join",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 635,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 635,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 635,
                                                        "char": 37
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "filteredJoinedContent",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "content",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 636,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 636,
                                                                    "char": 60
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 637,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "filteredContent",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "content",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 638,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 638,
                                                                    "char": 54
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 639,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 640,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 642,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "join",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 642,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 642,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "file_put_contents",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "targetPath",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 647,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 647,
                                                                "char": 49
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filteredContent",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 647,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 647,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 647,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 648,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 649,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 651,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "join",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 651,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 651,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "path",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 655,
                                                            "char": 42
                                                        },
                                                        "name": "getRealTargetUri",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 655,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 655,
                                                    "char": 61
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "prefixedPath",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 656,
                                                            "char": 41
                                                        },
                                                        "name": "getPrefixedPath",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 656,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 656,
                                                                "char": 68
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "path",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 656,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 656,
                                                                "char": 74
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 656,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 656,
                                                    "char": 75
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 658,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 658,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 658,
                                                            "char": 35
                                                        },
                                                        "name": "getVersion",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 658,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 658,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "asset",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 658,
                                                        "char": 58
                                                    },
                                                    "name": "isAutoVersion",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 658,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 658,
                                                "char": 75
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "version",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 659,
                                                                    "char": 35
                                                                },
                                                                "name": "getVersion",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 659,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 659,
                                                            "char": 48
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "autoVersion",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 660,
                                                                    "char": 35
                                                                },
                                                                "name": "isAutoVersion",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 660,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 660,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 662,
                                                    "char": 10
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "autoVersion",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 662,
                                                            "char": 25
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "local",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 662,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 662,
                                                        "char": 33
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "modificationTime",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "filemtime",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "asset",
                                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                        "line": 663,
                                                                                        "char": 52
                                                                                    },
                                                                                    "name": "getRealSourcePath",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 663,
                                                                                    "char": 72
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 663,
                                                                                "char": 72
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 663,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 663,
                                                                    "char": 73
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "version",
                                                                    "expr": {
                                                                        "type": "ternary",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "version",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 664,
                                                                            "char": 44
                                                                        },
                                                                        "right": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "version",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 664,
                                                                                    "char": 54
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": ".",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 664,
                                                                                    "char": 58
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 664,
                                                                                "char": 58
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "modificationTime",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 664,
                                                                                "char": 77
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 664,
                                                                            "char": 77
                                                                        },
                                                                        "extra": {
                                                                            "type": "variable",
                                                                            "value": "modificationTime",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 664,
                                                                            "char": 95
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 664,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 664,
                                                                    "char": 95
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 665,
                                                            "char": 9
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 667,
                                                    "char": 7
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 667,
                                                        "char": 17
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "prefixedPath",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "prefixedPath",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 668,
                                                                                "char": 39
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "?ver=",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 668,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 668,
                                                                            "char": 47
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "version",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 668,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 668,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 668,
                                                                    "char": 56
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 669,
                                                            "char": 6
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 670,
                                                    "char": 5
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 675,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "attributes",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "asset",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 675,
                                                            "char": 40
                                                        },
                                                        "name": "getAttributes",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 675,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 675,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 680,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 680,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 680,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 685,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 685,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 685,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 685,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 685,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "attributes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 686,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "prefixedPath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 686,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 686,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 687,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parameters",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "attributes",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 687,
                                                                            "char": 49
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 687,
                                                                        "char": 49
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 687,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 687,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 688,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parameters",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "prefixedPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 689,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 689,
                                                                        "char": 51
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 689,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 689,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 690,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 691,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "parameters",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "local",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 691,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 691,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 696,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "callback",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 696,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 696,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "parameters",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 696,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 696,
                                                                "char": 69
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 696,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 696,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 701,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "useImplicitOutput",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 701,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 701,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 701,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "echo",
                                                    "expressions": [
                                                        {
                                                            "type": "variable",
                                                            "value": "html",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 702,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 703,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "output",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "html",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 704,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 704,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 705,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 706,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 707,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 709,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filters",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 709,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 709,
                                        "char": 25
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 709,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "join",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 710,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 710,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 710,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "file_put_contents",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "completeTargetPath",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 715,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 715,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filteredJoinedContent",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 715,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 715,
                                                        "char": 76
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 715,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 720,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "targetUri",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 720,
                                                            "char": 47
                                                        },
                                                        "name": "getTargetUri",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 720,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 720,
                                                    "char": 62
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "prefixedPath",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 721,
                                                            "char": 41
                                                        },
                                                        "name": "getPrefixedPath",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "collection",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 721,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 721,
                                                                "char": 68
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "targetUri",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 721,
                                                                    "char": 79
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 721,
                                                                "char": 79
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 721,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 721,
                                                    "char": 80
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "version",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 722,
                                                            "char": 47
                                                        },
                                                        "name": "getVersion",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 722,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 722,
                                                    "char": 60
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "autoVersion",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 723,
                                                            "char": 47
                                                        },
                                                        "name": "isAutoVersion",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 723,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 723,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 725,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "autoVersion",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 725,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 725,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 725,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "modificationTime",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "filemtime",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "completeTargetPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 726,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 726,
                                                                        "char": 72
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 726,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 726,
                                                            "char": 73
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "version",
                                                            "expr": {
                                                                "type": "ternary",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "version",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 727,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "version",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 727,
                                                                            "char": 62
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ".",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 727,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 727,
                                                                        "char": 66
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "modificationTime",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 727,
                                                                        "char": 85
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 727,
                                                                    "char": 85
                                                                },
                                                                "extra": {
                                                                    "type": "variable",
                                                                    "value": "modificationTime",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 727,
                                                                    "char": 103
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 727,
                                                                "char": 103
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 727,
                                                            "char": 103
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 728,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 730,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "version",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 730,
                                                "char": 28
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "prefixedPath",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "prefixedPath",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 731,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "?ver=",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 731,
                                                                        "char": 61
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 731,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "version",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 731,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 731,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 731,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 732,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 737,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "attributes",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 737,
                                                            "char": 45
                                                        },
                                                        "name": "getAttributes",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 737,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 737,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 742,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 742,
                                                            "char": 40
                                                        },
                                                        "name": "getTargetLocal",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 742,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 742,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 747,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 747,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 747,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 747,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 747,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "attributes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 748,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "prefixedPath",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 748,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 748,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parameters",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "attributes",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 749,
                                                                            "char": 49
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 749,
                                                                        "char": 49
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 749,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 749,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 750,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "parameters",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "prefixedPath",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 751,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 751,
                                                                        "char": 51
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 751,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 751,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 752,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 753,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "parameters",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "local",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 753,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 753,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 758,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "callback",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 758,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 758,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "parameters",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 758,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 758,
                                                                "char": 69
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 758,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 758,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 763,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "useImplicitOutput",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 763,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 763,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 763,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "echo",
                                                    "expressions": [
                                                        {
                                                            "type": "variable",
                                                            "value": "html",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 764,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 765,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "output",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "html",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 766,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 766,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 767,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 768,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 769,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 771,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "output",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 771,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 772,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Traverses a collection calling the callback to generate its HTML\n     *\n     * @param callback callback\n     * @param string type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 346,
                                "char": 79
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 347,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 347,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 346,
                    "last-line": 776,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "outputCss",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collectionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 777,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 777,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "callback",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 779,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 780,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 780,
                                    "char": 23
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 780,
                                    "char": 34
                                },
                                {
                                    "variable": "tag",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 780,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 782,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "collectionName",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 782,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 782,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 783,
                                                    "char": 35
                                                },
                                                "name": "getCss",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 783,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 783,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 784,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 785,
                                                    "char": 35
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "collectionName",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 785,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 785,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 785,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 785,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 786,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 788,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "callback",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "Phalcon\\\\Tag",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 788,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 788,
                                                "char": 38
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "stylesheetLink",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 788,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 788,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 788,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 788,
                                    "char": 55
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 789,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 789,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 789,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 789,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 791,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 791,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 791,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 791,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 791,
                                    "char": 40
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 791,
                                        "char": 52
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "tag",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 791,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 791,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 791,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 791,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tag",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 792,
                                                    "char": 38
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "tag",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 792,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 792,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 792,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 792,
                                            "char": 53
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "callback",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "tag",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 793,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 793,
                                                        "char": 32
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "string",
                                                            "value": "stylesheetLink",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 793,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 793,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 793,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 793,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 794,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 796,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 796,
                                    "char": 21
                                },
                                "name": "output",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 796,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 796,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "callback",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 796,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 796,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "css",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 796,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 796,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 796,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 797,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prints the HTML for CSS assets\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 778,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 778,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 777,
                    "last-line": 803,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "outputInline",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 804,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 804,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 804,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "html",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 806,
                                    "char": 20
                                },
                                {
                                    "variable": "joinedContent",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 806,
                                    "char": 35
                                },
                                {
                                    "variable": "output",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 806,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 807,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 23
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 29
                                },
                                {
                                    "variable": "codes",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 36
                                },
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 45
                                },
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 53
                                },
                                {
                                    "variable": "filters",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 62
                                },
                                {
                                    "variable": "join",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 807,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 809,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "output",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 809,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 809,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 810,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 810,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "joinedContent",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 811,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 811,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "codes",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 812,
                                            "char": 40
                                        },
                                        "name": "getCodes",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 812,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 812,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filters",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 813,
                                            "char": 40
                                        },
                                        "name": "getFilters",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 813,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 813,
                                    "char": 53
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "join",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 814,
                                            "char": 40
                                        },
                                        "name": "getJoin",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 814,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 814,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 816,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "codes",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 816,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 816,
                                        "char": 23
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 816,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "codes",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 817,
                                        "char": 31
                                    },
                                    "value": "code",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "attributes",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "code",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 818,
                                                            "char": 39
                                                        },
                                                        "name": "getAttributes",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 818,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 818,
                                                    "char": 55
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "content",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "code",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 819,
                                                            "char": 36
                                                        },
                                                        "name": "getContent",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 819,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 819,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 821,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "filters",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 821,
                                                "char": 39
                                            },
                                            "value": "filter",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "not-equals",
                                                            "left": {
                                                                "type": "typeof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "filter",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 825,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 825,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "object",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 825,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 825,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 825,
                                                        "char": 57
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
                                                                            "value": "Filter is invalid",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 826,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 826,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 826,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 827,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 833,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "content",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "filter",
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 833,
                                                                    "char": 42
                                                                },
                                                                "name": "filter",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "content",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 833,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 833,
                                                                        "char": 57
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 833,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 833,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 834,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 836,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "join",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 836,
                                                "char": 25
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "joinedContent",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "content",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 837,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 837,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 838,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "html",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "scall",
                                                                        "dynamic-class": 0,
                                                                        "class": "Tag",
                                                                        "dynamic": 0,
                                                                        "name": "tagHtml",
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "type",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 839,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 839,
                                                                                "char": 49
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "attributes",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 839,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 839,
                                                                                "char": 61
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "bool",
                                                                                    "value": "false",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 839,
                                                                                    "char": 68
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 839,
                                                                                "char": 68
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "bool",
                                                                                    "value": "true",
                                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                    "line": 839,
                                                                                    "char": 74
                                                                                },
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 839,
                                                                                "char": 74
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 840,
                                                                        "char": 31
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "content",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 841,
                                                                        "char": 31
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 841,
                                                                    "char": 31
                                                                },
                                                                "right": {
                                                                    "type": "scall",
                                                                    "dynamic-class": 0,
                                                                    "class": "Tag",
                                                                    "dynamic": 0,
                                                                    "name": "tagHtmlClose",
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "type",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 841,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 841,
                                                                            "char": 55
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "bool",
                                                                                "value": "true",
                                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                                "line": 841,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 841,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 841,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 841,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 841,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 842,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 843,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 845,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "join",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 845,
                                        "char": 21
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Tag",
                                                                "dynamic": 0,
                                                                "name": "tagHtml",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "type",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 846,
                                                                            "char": 45
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 846,
                                                                        "char": 45
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "attributes",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 846,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 846,
                                                                        "char": 57
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "bool",
                                                                            "value": "false",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 846,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 846,
                                                                        "char": 64
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "bool",
                                                                            "value": "true",
                                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                            "line": 846,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 846,
                                                                        "char": 70
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 847,
                                                                "char": 27
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "joinedContent",
                                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                "line": 848,
                                                                "char": 27
                                                            },
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 848,
                                                            "char": 27
                                                        },
                                                        "right": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Tag",
                                                            "dynamic": 0,
                                                            "name": "tagHtmlClose",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "type",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 848,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 848,
                                                                    "char": 51
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                        "line": 848,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                                    "line": 848,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 848,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 848,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 848,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 849,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 854,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 854,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "implicitOutput",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 854,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 854,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 854,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 854,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "echo",
                                            "expressions": [
                                                {
                                                    "type": "variable",
                                                    "value": "html",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 855,
                                                    "char": 26
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 856,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "html",
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 857,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 857,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 858,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 859,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 861,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "output",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 861,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 862,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Traverses a collection and generate its HTML\n     *\n     * @param string type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 805,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 805,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 804,
                    "last-line": 866,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "outputInlineCss",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collectionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 867,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 867,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 869,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 871,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "collectionName",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 871,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 871,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 872,
                                                    "char": 35
                                                },
                                                "name": "getCss",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 872,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 872,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 873,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 874,
                                                    "char": 35
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "collectionName",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 874,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 874,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 874,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 874,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 875,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 877,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 877,
                                    "char": 21
                                },
                                "name": "outputInline",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 877,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 877,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "style",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 877,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 877,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 877,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 878,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prints the HTML for inline CSS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 868,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 868,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 867,
                    "last-line": 882,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "outputInlineJs",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collectionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 883,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 883,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 885,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 887,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "collectionName",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 887,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 887,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 888,
                                                    "char": 35
                                                },
                                                "name": "getJs",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 888,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 888,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 889,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 890,
                                                    "char": 35
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "collectionName",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 890,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 890,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 890,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 890,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 891,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 893,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 893,
                                    "char": 21
                                },
                                "name": "outputInline",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 893,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 893,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "script",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 893,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 893,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 893,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 894,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prints the HTML for inline JS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 884,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 884,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 883,
                    "last-line": 898,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "outputJs",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collectionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 899,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 899,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "callback",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 901,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 902,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 902,
                                    "char": 23
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 902,
                                    "char": 34
                                },
                                {
                                    "variable": "tag",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 902,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 904,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "collectionName",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 904,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 904,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 905,
                                                    "char": 35
                                                },
                                                "name": "getJs",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 905,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 905,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 906,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 907,
                                                    "char": 35
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "collectionName",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 907,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 907,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 907,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 907,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 908,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 910,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "callback",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "Phalcon\\\\Tag",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 910,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 910,
                                                "char": 37
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "javascriptInclude",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 910,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 910,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 910,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 910,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 912,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 912,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 912,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 912,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 912,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 913,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 913,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 913,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 913,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 913,
                                    "char": 40
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 913,
                                        "char": 52
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "tag",
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 913,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 913,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 913,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 913,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tag",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                    "line": 914,
                                                    "char": 38
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "tag",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 914,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 914,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 914,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 914,
                                            "char": 53
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "callback",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "tag",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 915,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 915,
                                                        "char": 32
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "string",
                                                            "value": "javascriptInclude",
                                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                            "line": 915,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                        "line": 915,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                                "line": 915,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 915,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 916,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 918,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 918,
                                    "char": 21
                                },
                                "name": "output",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 918,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 918,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "callback",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 918,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 918,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "js",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 918,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 918,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 918,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 919,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prints the HTML for JS assets\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 900,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 900,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 899,
                    "last-line": 927,
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
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 928,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 928,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 928,
                            "char": 60
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
                                    "property": "collections",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 930,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "collection",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 930,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 930,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 932,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 932,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 933,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a collection in the Assets Manager\n     *\n     *```php\n     * $assets->set(\"js\", $collection);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 929,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 929,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 929,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 928,
                    "last-line": 937,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
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
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 938,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 938,
                            "char": 50
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
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 940,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 940,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 941,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 939,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 938,
                    "last-line": 945,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 946,
                            "char": 46
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
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 948,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 948,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 950,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 950,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 951,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the manager options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 947,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 947,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 947,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 946,
                    "last-line": 955,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useImplicitOutput",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "implicitOutput",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 956,
                            "char": 58
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
                                    "property": "implicitOutput",
                                    "expr": {
                                        "type": "variable",
                                        "value": "implicitOutput",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 958,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 958,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 960,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 960,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 961,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the HTML generated must be directly printed or returned\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Manager",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 957,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 957,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 957,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 956,
                    "last-line": 965,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getPrefixedPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 966,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 966,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 966,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "prefix",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 968,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 970,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefix",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                            "line": 970,
                                            "char": 33
                                        },
                                        "name": "getPrefix",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 970,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 970,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 972,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "prefix",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 972,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 972,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                        "line": 973,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 974,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 976,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "prefix",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 976,
                                    "char": 23
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "path",
                                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                    "line": 976,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 976,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Assets\/Manager.zep",
                            "line": 977,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the prefixed path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Manager.zep",
                                "line": 967,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Manager.zep",
                        "line": 967,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Manager.zep",
                    "line": 966,
                    "last-line": 978,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Manager.zep",
            "line": 29,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Manager.zep",
        "line": 29,
        "char": 5
    }
]