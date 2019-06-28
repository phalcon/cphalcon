[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets",
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Countable",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 13,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Iterator",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 14,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 15,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\FilterInterface",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 16,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Inline",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 17,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset\\Css",
                "alias": "AssetCss",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset\\Js",
                "alias": "AssetJs",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 19,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Inline\\Js",
                "alias": "InlineJs",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 20,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Inline\\Css",
                "alias": "InlineCss",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 21,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents a collection of assets\n *",
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Collection",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "Countable",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 26,
                "char": 38
            },
            {
                "type": "variable",
                "value": "Iterator",
                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                "line": 27,
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
                    "name": "assets",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 31,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 31,
                            "char": 33
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "attributes",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 36,
                        "char": 31
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 36,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 41,
                    "char": 3
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "autoVersion",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 42,
                        "char": 32
                    },
                    "docblock": "**\n\t * Should version be determined from file modification time\n\t * @var bool\n\t *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 42,
                            "char": 38
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "codes",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 47,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 47,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "filters",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 52,
                        "char": 28
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 52,
                            "char": 34
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 56,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "includedAssets",
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 61,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "join",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 62,
                        "char": 27
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 62,
                            "char": 33
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 66,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "local",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 67,
                        "char": 28
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 67,
                            "char": 34
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 71,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "prefix",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 72,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 76,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "position",
                    "docblock": "**\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 77,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 81,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sourcePath",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 82,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 86,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "targetLocal",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 87,
                        "char": 34
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 87,
                            "char": 40
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 91,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "targetPath",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 92,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 96,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "targetUri",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 97,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 102,
                    "char": 3
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "version",
                    "docblock": "**\n\t * Version of resource\n\t * @var string\n\t *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 103,
                            "char": 25
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 103,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 107,
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
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "includedAssets",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 110,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 110,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Assets\\Collection constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 108,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "asset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AssetInterface",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 116,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 116,
                            "char": 47
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
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 118,
                                    "char": 14
                                },
                                "name": "addAsset",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "asset",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 118,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 118,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 118,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 120,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 120,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 121,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a asset to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 117,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 116,
                    "last-line": 125,
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
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 127,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 128,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 128,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 129,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 129,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 130,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 130,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 131,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 131,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 133,
                                "char": 2
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 133,
                            "char": 2
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collectionLocal",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 135,
                                    "char": 28
                                },
                                {
                                    "variable": "collectionAttributes",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 135,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 137,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "local",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 137,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 137,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 137,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 137,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionLocal",
                                            "expr": {
                                                "type": "variable",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 138,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 138,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 139,
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
                                            "variable": "collectionLocal",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 140,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 140,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 140,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 140,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 141,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 143,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 143,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 143,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 143,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 143,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 144,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 144,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 145,
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
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 146,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 146,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 146,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 146,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 147,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 149,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 149,
                                    "char": 14
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
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
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 150,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 150,
                                                    "char": 30
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "collectionLocal",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 150,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 150,
                                                    "char": 47
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 150,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 150,
                                                    "char": 55
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "collectionAttributes",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 150,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 150,
                                                    "char": 77
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 150,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 150,
                                                    "char": 86
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "autoVersion",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 150,
                                                        "char": 99
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 150,
                                                    "char": 99
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 151,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 151,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 151,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 153,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 153,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 154,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a CSS asset to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 134,
                                    "char": 2
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 134,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 134,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 126,
                    "last-line": 158,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addFilter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "FilterInterface",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 159,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 159,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "filters",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filter",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 161,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 161,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 163,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 163,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 164,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a filter to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 160,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 160,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 160,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 159,
                    "last-line": 168,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addInline",
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 169,
                                "char": 43
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 169,
                            "char": 44
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
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 171,
                                    "char": 14
                                },
                                "name": "addAsset",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "code",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 171,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 171,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 171,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 173,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 173,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 174,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an inline code to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 170,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 170,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 170,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 169,
                    "last-line": 178,
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
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 179,
                            "char": 48
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 179,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 179,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 179,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 179,
                            "char": 87
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collectionAttributes",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 181,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 183,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 183,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 183,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 183,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 183,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 184,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 184,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 185,
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
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 186,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 186,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 186,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 186,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 187,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 189,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "codes",
                                    "expr": {
                                        "type": "new",
                                        "class": "InlineCss",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "content",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 190,
                                                    "char": 20
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 190,
                                                "char": 20
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filter",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 191,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 191,
                                                "char": 19
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "collectionAttributes",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 193,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 193,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 193,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 193,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 195,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 195,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 196,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an inline CSS to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 180,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 180,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 180,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 179,
                    "last-line": 200,
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
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 201,
                            "char": 47
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 201,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 201,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 201,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 201,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collectionAttributes",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 203,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 205,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 205,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 205,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 205,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 205,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 206,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 206,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 207,
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
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 208,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 208,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 208,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 208,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 209,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 211,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "codes",
                                    "expr": {
                                        "type": "new",
                                        "class": "InlineJs",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "content",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 211,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 211,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filter",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 211,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 211,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "collectionAttributes",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 211,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 211,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 211,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 211,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 213,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 213,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 214,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an inline javascript to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 202,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 202,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 202,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 201,
                    "last-line": 220,
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
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 222,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 223,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 223,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 224,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 224,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 225,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 225,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 226,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 226,
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
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 228,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 228,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collectionLocal",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 230,
                                    "char": 28
                                },
                                {
                                    "variable": "collectionAttributes",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 230,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 232,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "local",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 232,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 232,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 232,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 232,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionLocal",
                                            "expr": {
                                                "type": "variable",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 233,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 233,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 234,
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
                                            "variable": "collectionLocal",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 235,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 235,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 235,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 235,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 236,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 238,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 238,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 238,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 238,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 238,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 239,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 239,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 240,
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
                                            "variable": "collectionAttributes",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 241,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 241,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 241,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 241,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 242,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 244,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 244,
                                    "char": 14
                                },
                                "name": "add",
                                "call-type": 1,
                                "parameters": [
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
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 245,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 245,
                                                    "char": 29
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "collectionLocal",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 245,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 245,
                                                    "char": 46
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 245,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 245,
                                                    "char": 54
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "collectionAttributes",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 245,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 245,
                                                    "char": 76
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 245,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 245,
                                                    "char": 85
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "autoVersion",
                                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                        "line": 245,
                                                        "char": 98
                                                    },
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 245,
                                                    "char": 98
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 246,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 246,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 246,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 248,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 248,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 249,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a javascript asset to the collection\n     *\n     * @param array attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 229,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 229,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 229,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 221,
                    "last-line": 253,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "count",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 256,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "assets",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 256,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 256,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 256,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 256,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 257,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the number of elements in the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 255,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 255,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 254,
                    "last-line": 261,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "current",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 264,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "assets",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 264,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 264,
                                    "char": 28
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 264,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "position",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 264,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 264,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 264,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 265,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current asset in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Asset",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 263,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 263,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 263,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 262,
                    "last-line": 270,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRealTargetPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "basePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 271,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "targetPath",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 273,
                                    "char": 23
                                },
                                {
                                    "variable": "completePath",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 273,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 275,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "targetPath",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 275,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "targetPath",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 275,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 275,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 275,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 280,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "completePath",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "basePath",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 280,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "targetPath",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 280,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 280,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 280,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 286,
                            "char": 10
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
                                            "value": "completePath",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 286,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 286,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 286,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "realPath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "completePath",
                                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                    "line": 287,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 287,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 287,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 288,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 290,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "completePath",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 290,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 291,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the complete location where the joined\/filtered collection must\n     * be written\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 272,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 272,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 271,
                    "last-line": 307,
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
                            "name": "asset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AssetInterface",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 308,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 308,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 310,
                                    "char": 16
                                },
                                {
                                    "variable": "assets",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 310,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 312,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "asset",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 312,
                                            "char": 25
                                        },
                                        "name": "getAssetKey",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 312,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 312,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "assets",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 313,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "includedAssets",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 313,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 313,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 313,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 315,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "in_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 315,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 315,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "assets",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 315,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 315,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 315,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 316,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks this the asset is added to the collection.\n     *\n     * ```php\n     * use Phalcon\\Assets\\Asset;\n     * use Phalcon\\Assets\\Collection;\n     *\n     * $collection = new Collection();\n     *\n     * $asset = new Asset(\"js\", \"js\/jquery.js\");\n     *\n     * $collection->add($asset);\n     * $collection->has($asset); \/\/ true\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 309,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 309,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 308,
                    "last-line": 320,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAutoVersion",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 323,
                                    "char": 18
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "autoVersion",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 323,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 323,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 324,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n     * Checks if collection is using auto version\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 322,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 322,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 321,
                    "last-line": 329,
                    "char": 16
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "join",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "join",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 330,
                            "char": 35
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
                                    "property": "join",
                                    "expr": {
                                        "type": "variable",
                                        "value": "join",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 332,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 332,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 334,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 334,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 335,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if all filtered assets in the collection must be joined in a single\n     * result file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 331,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 331,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 331,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 330,
                    "last-line": 339,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "key",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 342,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "position",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 342,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 342,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 343,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current position\/key in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 341,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 341,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 340,
                    "last-line": 347,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "next",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-incr",
                                    "variable": "this",
                                    "property": "position",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 350,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 351,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves the internal iteration pointer to the next position\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 349,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 348,
                    "last-line": 355,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rewind",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "position",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 358,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 358,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 359,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rewinds the internal iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 357,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 356,
                    "last-line": 363,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 364,
                            "char": 52
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
                                    "property": "attributes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 366,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 366,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 368,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 368,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 369,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets extra HTML attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 365,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 365,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 365,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 364,
                    "last-line": 373,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFilters",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 374,
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
                                    "property": "filters",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filters",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 376,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 376,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 378,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 378,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 379,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an array of filters in the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 375,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 375,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 375,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 374,
                    "last-line": 383,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLocal",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 384,
                            "char": 41
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
                                    "property": "local",
                                    "expr": {
                                        "type": "variable",
                                        "value": "local",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 386,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 386,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 388,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 388,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 389,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the collection uses local assets by default\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 385,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 385,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 385,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 384,
                    "last-line": 393,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPrefix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "prefix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 394,
                            "char": 45
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
                                    "property": "prefix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 396,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 396,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 398,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 398,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 399,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a common prefix for all the assets\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 395,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 395,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 395,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 394,
                    "last-line": 403,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTargetLocal",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "targetLocal",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 404,
                            "char": 53
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
                                    "property": "targetLocal",
                                    "expr": {
                                        "type": "variable",
                                        "value": "targetLocal",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 406,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 406,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 408,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 408,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 409,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the target local\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 405,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 405,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 405,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 404,
                    "last-line": 413,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTargetPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "targetPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 414,
                            "char": 53
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
                                    "property": "targetPath",
                                    "expr": {
                                        "type": "variable",
                                        "value": "targetPath",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 416,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 416,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 418,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 418,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 419,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the target path of the file for the filtered\/join output\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 415,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 415,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 415,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 414,
                    "last-line": 423,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTargetUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "targetUri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 424,
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
                                    "property": "targetUri",
                                    "expr": {
                                        "type": "variable",
                                        "value": "targetUri",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 426,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 426,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 428,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 428,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 429,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a target uri for the generated HTML\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 425,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 425,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 425,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 424,
                    "last-line": 433,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setSourcePath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sourcePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 434,
                            "char": 53
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
                                    "property": "sourcePath",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sourcePath",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 436,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 436,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 438,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 438,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 439,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a base source path for all the assets in this collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 435,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 435,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 435,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 434,
                    "last-line": 443,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "valid",
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
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 446,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "assets",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 446,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 446,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 446,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 446,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 446,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 446,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 446,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 447,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the current element in the iterator is valid\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 445,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 445,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 444,
                    "last-line": 451,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "protected"
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
                                "value": "AssetInterface",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 452,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 452,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 454,
                                    "char": 17
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "asset",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 454,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 454,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 454,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 455,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 456,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 458,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "instanceof",
                                "left": {
                                    "type": "variable",
                                    "value": "asset",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 458,
                                    "char": 27
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "Asset",
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 458,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 458,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "assets",
                                            "expr": {
                                                "type": "variable",
                                                "value": "asset",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 459,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 459,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 460,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "codes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "asset",
                                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                                "line": 461,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 461,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 462,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 464,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "includedAssets",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "asset",
                                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                            "line": 464,
                                            "char": 44
                                        },
                                        "name": "getAssetKey",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                        "line": 464,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                    "line": 464,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 466,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 466,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Collection.zep",
                            "line": 467,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a asset or inline-code to the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Collection.zep",
                                "line": 453,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Collection.zep",
                        "line": 453,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Collection.zep",
                    "line": 452,
                    "last-line": 468,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Collection.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Collection.zep",
        "line": 26,
        "char": 5
    }
]