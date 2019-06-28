[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Debug",
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ErrorException",
                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                "line": 13,
                "char": 19
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Version",
                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                "line": 15,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                "line": 16,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionClass",
                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                "line": 17,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionFunction",
                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                "line": 18,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Provides debug capabilities to Phalcon applications\n *",
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "Debug",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "blacklist",
                    "default": {
                        "type": "array",
                        "left": [
                            {
                                "key": {
                                    "type": "string",
                                    "value": "request",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 28,
                                    "char": 36
                                },
                                "value": {
                                    "type": "empty-array",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 28,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 28,
                                "char": 40
                            },
                            {
                                "key": {
                                    "type": "string",
                                    "value": "server",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 28,
                                    "char": 49
                                },
                                "value": {
                                    "type": "empty-array",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 28,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 28,
                                "char": 53
                            }
                        ],
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 28,
                        "char": 54
                    },
                    "docblock": "**\n     * @var array\n    *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 30,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "data",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "hideDocumentRoot",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 35,
                        "char": 39
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "isActive",
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 44,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "showBackTrace",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 45,
                        "char": 35
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 49,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "showFileFragment",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 50,
                        "char": 39
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 54,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "showFiles",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 55,
                        "char": 31
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 59,
                    "char": 5
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "uri",
                    "default": {
                        "type": "string",
                        "value": "https:\/\/assets.phalconphp.com\/debug\/4.0.x\/",
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 60,
                        "char": 63
                    },
                    "docblock": "**\n     * @var string\n    *",
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 64,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clearVars",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 67,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 67,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 69,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 69,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 70,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Clears are variables added previously\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 66,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 66,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 66,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 65,
                    "last-line": 74,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "debugVar",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "varz",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 75,
                            "char": 34
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 75,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 75,
                            "char": 53
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
                                    "property": "data",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "varz",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 78,
                                                    "char": 17
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 78,
                                                "char": 17
                                            },
                                            {
                                                "value": {
                                                    "type": "fcall",
                                                    "name": "debug_backtrace",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 79,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 79,
                                                "char": 30
                                            },
                                            {
                                                "value": {
                                                    "type": "fcall",
                                                    "name": "time",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 81,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 81,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 81,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 81,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 83,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 83,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a variable to the debug output\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 76,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 76,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 76,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 75,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCssSources",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "uri",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 91,
                                    "char": 16
                                },
                                {
                                    "variable": "sources",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 91,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 93,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 93,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 93,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 93,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 93,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 95,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<link rel='stylesheet' type='text\/css' href='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 95,
                                                "char": 70
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 95,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 95,
                                            "char": 76
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "bower_components\/jquery-ui\/themes\/ui-lightness\/jquery-ui.min.css' \/>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 95,
                                            "char": 146
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 95,
                                        "char": 146
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 95,
                                    "char": 146
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 96,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<link rel='stylesheet' type='text\/css' href='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 96,
                                                "char": 69
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 96,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 96,
                                            "char": 75
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "bower_components\/jquery-ui\/themes\/ui-lightness\/theme.css' \/>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 96,
                                            "char": 137
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 96,
                                        "char": 137
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 96,
                                    "char": 137
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 97,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<link rel='stylesheet' type='text\/css' href='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 97,
                                                "char": 69
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 97,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 97,
                                            "char": 75
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "themes\/default\/style.css' \/>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 97,
                                            "char": 105
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 97,
                                        "char": 105
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 97,
                                    "char": 105
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 99,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sources",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 99,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 100,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the css sources\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 90,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 89,
                    "last-line": 104,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getJsSources",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "uri",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 107,
                                    "char": 16
                                },
                                {
                                    "variable": "sources",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 107,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 109,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 109,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 109,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 109,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 109,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 111,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<script type='text\/javascript' src='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 111,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 111,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 111,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "bower_components\/jquery\/dist\/jquery.min.js'><\/script>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 111,
                                            "char": 122
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 111,
                                        "char": 122
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 111,
                                    "char": 122
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 112,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<script type='text\/javascript' src='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 112,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 112,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 112,
                                            "char": 66
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "bower_components\/jquery-ui\/jquery-ui.min.js'><\/script>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 112,
                                            "char": 122
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 112,
                                        "char": 122
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 112,
                                    "char": 122
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 113,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<script type='text\/javascript' src='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 113,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 113,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 113,
                                            "char": 66
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "bower_components\/jquery.scrollTo\/jquery.scrollTo.min.js'><\/script>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 113,
                                            "char": 134
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 113,
                                        "char": 134
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 113,
                                    "char": 134
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 114,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<script type='text\/javascript' src='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 114,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 114,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 114,
                                            "char": 66
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "prettify\/prettify.js'><\/script>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 114,
                                            "char": 99
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 114,
                                        "char": 99
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 114,
                                    "char": 99
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 115,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sources",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<script type='text\/javascript' src='",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 115,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 115,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 115,
                                            "char": 66
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "pretty.js'><\/script>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 115,
                                            "char": 88
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 115,
                                        "char": 88
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 115,
                                    "char": 88
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 117,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sources",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 117,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the javascript sources\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 106,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 106,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 105,
                    "last-line": 122,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getVersion",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "link",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 125,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 127,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "link",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 128,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "https:\/\/docs.phalconphp.com\/",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 128,
                                                                    "char": 50
                                                                },
                                                                "right": {
                                                                    "type": "scall",
                                                                    "dynamic-class": 0,
                                                                    "class": "Version",
                                                                    "dynamic": 0,
                                                                    "name": "getPart",
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "static-constant-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "Version",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 128,
                                                                                    "char": 91
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "VERSION_MAJOR",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 128,
                                                                                    "char": 91
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 128,
                                                                                "char": 91
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 128,
                                                                            "char": 91
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 128,
                                                                    "char": 93
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 128,
                                                                "char": 93
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": ".",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 128,
                                                                "char": 97
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 128,
                                                            "char": 97
                                                        },
                                                        "right": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Version",
                                                            "dynamic": 0,
                                                            "name": "getPart",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "static-constant-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "Version",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 128,
                                                                            "char": 139
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "VERSION_MEDIUM",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 128,
                                                                            "char": 139
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 128,
                                                                        "char": 139
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 128,
                                                                    "char": 139
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 128,
                                                            "char": 141
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 128,
                                                        "char": 141
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\/en\/",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 128,
                                                        "char": 147
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 128,
                                                    "char": 147
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 128,
                                                "char": 147
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 129,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Version",
                                                    "dynamic": 0,
                                                    "name": "get",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 129,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 129,
                                                "char": 35
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 130,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 130,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 130,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "target",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 131,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "_new",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 132,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 132,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 132,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 132,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 134,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "<div class='version'>Phalcon Framework ",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 134,
                                        "char": 56
                                    },
                                    "right": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Tag",
                                        "dynamic": 0,
                                        "name": "linkTo",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "link",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 134,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 134,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 134,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 134,
                                    "char": 76
                                },
                                "right": {
                                    "type": "string",
                                    "value": "<\/div>",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 134,
                                    "char": 84
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 134,
                                "char": 84
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 135,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a link to the current version documentation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 124,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 123,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "halt",
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
                                            "value": "Halted request",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 142,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 142,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 142,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Halts the request showing a backtrace\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 140,
                    "last-line": 147,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "listen",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "exceptions",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 148,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 148,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "lowSeverity",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 148,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 148,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "exceptions",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 150,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 151,
                                            "char": 18
                                        },
                                        "name": "listenExceptions",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 151,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 154,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "lowSeverity",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 154,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 155,
                                            "char": 18
                                        },
                                        "name": "listenLowSeverity",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 155,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 156,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 158,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 158,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 159,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Listen for uncaught exceptions and unsilent notices or warnings\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 149,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 149,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 149,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 148,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "listenExceptions",
                    "statements": [
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "set_exception_handler",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 167,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 167,
                                                    "char": 18
                                                },
                                                {
                                                    "value": {
                                                        "type": "string",
                                                        "value": "onUncaughtException",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 167,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 167,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 168,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 168,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 168,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 170,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 170,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 171,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Listen for uncaught exceptions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 165,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 164,
                    "last-line": 175,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "listenLowSeverity",
                    "statements": [
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "set_error_handler",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 179,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 179,
                                                    "char": 18
                                                },
                                                {
                                                    "value": {
                                                        "type": "string",
                                                        "value": "onUncaughtLowSeverity",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 179,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 179,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 180,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 180,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 180,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 182,
                            "char": 29
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "set_exception_handler",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 183,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 183,
                                                    "char": 18
                                                },
                                                {
                                                    "value": {
                                                        "type": "string",
                                                        "value": "onUncaughtException",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 183,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 183,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 184,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 184,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 184,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 186,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 186,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 187,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Listen for unsilent notices or warnings\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 177,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 177,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 177,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 176,
                    "last-line": 191,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "onUncaughtException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "exception",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "\\Exception",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 192,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 192,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "blacklist",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 194,
                                    "char": 22
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 194,
                                    "char": 33
                                },
                                {
                                    "variable": "dataVar",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 194,
                                    "char": 42
                                },
                                {
                                    "variable": "dataVars",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 194,
                                    "char": 52
                                },
                                {
                                    "variable": "escapedMessage",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 194,
                                    "char": 68
                                },
                                {
                                    "variable": "html",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 194,
                                    "char": 74
                                },
                                {
                                    "variable": "keyFile",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 20
                                },
                                {
                                    "variable": "keyRequest",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 32
                                },
                                {
                                    "variable": "keyServer",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 43
                                },
                                {
                                    "variable": "keyVar",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 51
                                },
                                {
                                    "variable": "n",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 54
                                },
                                {
                                    "variable": "showBackTrace",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 69
                                },
                                {
                                    "variable": "traceItem",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 195,
                                    "char": 80
                                },
                                {
                                    "variable": "obLevel",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 196,
                                    "char": 20
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 196,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "obLevel",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ob_get_level",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 198,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 198,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 203,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "obLevel",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 203,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 203,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 203,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ob_end_clean",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 204,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 205,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 210,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 210,
                                    "char": 27
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "isActive",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 210,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 210,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "echo",
                                    "expressions": [
                                        {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "exception",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 211,
                                                "char": 28
                                            },
                                            "name": "getMessage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 211,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 213,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 214,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 219,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "isActive",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 219,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 219,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 221,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "exception",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 221,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 221,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 221,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 221,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 226,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapedMessage",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 226,
                                            "char": 35
                                        },
                                        "name": "escapeString",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "exception",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 227,
                                                        "char": 23
                                                    },
                                                    "name": "getMessage",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 228,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 228,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 228,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 228,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 234,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "<html><head><title>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 234,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 234,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 234,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ": ",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 234,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 234,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "escapedMessage",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 234,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 234,
                                            "char": 74
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/title>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 234,
                                            "char": 84
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 234,
                                        "char": 84
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 234,
                                    "char": 84
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 235,
                            "char": 11
                        },
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
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 235,
                                                "char": 25
                                            },
                                            "name": "getCssSources",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 235,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/head><body>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 235,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 235,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 235,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 240,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 240,
                                            "char": 25
                                        },
                                        "name": "getVersion",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 240,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 240,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 245,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "string",
                                        "value": "<div align='center'><div class='error-main'>",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 245,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 245,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 246,
                            "char": 11
                        },
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
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "<h1>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 246,
                                                        "char": 25
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 246,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 246,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ": ",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 246,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 246,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "escapedMessage",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 246,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 246,
                                            "char": 59
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/h1>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 246,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 246,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 246,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 247,
                            "char": 11
                        },
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
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "<span class='error-file'>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 247,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "exception",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 247,
                                                            "char": 58
                                                        },
                                                        "name": "getFile",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 247,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 247,
                                                    "char": 69
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " (",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 247,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 247,
                                                "char": 74
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "exception",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 247,
                                                    "char": 86
                                                },
                                                "name": "getLine",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 247,
                                                "char": 97
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 247,
                                            "char": 97
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")<\/span>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 247,
                                            "char": 107
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 247,
                                        "char": 107
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 247,
                                    "char": 107
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 248,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "string",
                                        "value": "<\/div>",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 248,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 248,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 250,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "showBackTrace",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 250,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "showBackTrace",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 250,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 250,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 250,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 255,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "showBackTrace",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 255,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "dataVars",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 256,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 256,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 256,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 256,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 261,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<div class='error-info'><div id='tabs'><ul>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 261,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 261,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 262,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<li><a href='#error-tabs-1'>Backtrace<\/a><\/li>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 262,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 262,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 263,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<li><a href='#error-tabs-2'>Request<\/a><\/li>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 263,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 263,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 264,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<li><a href='#error-tabs-3'>Server<\/a><\/li>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 264,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 264,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 265,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<li><a href='#error-tabs-4'>Included Files<\/a><\/li>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 265,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 265,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 266,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<li><a href='#error-tabs-5'>Memory<\/a><\/li>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 266,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 266,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 268,
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
                                                "value": "dataVars",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 268,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 268,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 268,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 268,
                                        "char": 41
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
                                                        "type": "string",
                                                        "value": "<li><a href='#error-tabs-6'>Variables<\/a><\/li>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 269,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 269,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 270,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 272,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/ul>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 272,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 272,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 277,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<div id='error-tabs-1'><table cellspacing='0' align='center' width='100%'>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 277,
                                                "char": 98
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 277,
                                            "char": 98
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 279,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "exception",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 279,
                                            "char": 43
                                        },
                                        "name": "getTrace",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 279,
                                        "char": 56
                                    },
                                    "key": "n",
                                    "value": "traceItem",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 283,
                                                            "char": 33
                                                        },
                                                        "name": "showTraceItem",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "n",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 283,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 283,
                                                                "char": 49
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "traceItem",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 283,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 283,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 283,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 283,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 284,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 286,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/table><\/div>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 286,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 286,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 291,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<div id='error-tabs-2'><table cellspacing='0' align='center' class='superglobal-detail'>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 291,
                                                "char": 112
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 291,
                                            "char": 112
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 292,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<tr><th>Key<\/th><th>Value<\/th><\/tr>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 292,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 292,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 293,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "blacklist",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Arr",
                                                "dynamic": 0,
                                                "name": "get",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 293,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "blacklist",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 293,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 293,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 293,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "request",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 293,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 293,
                                                        "char": 62
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "empty-array",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 293,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 293,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 293,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 293,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 295,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "_REQUEST",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 295,
                                        "char": 47
                                    },
                                    "key": "keyRequest",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 296,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "blacklist",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 296,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "strtolower",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "keyRequest",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 296,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 296,
                                                                        "char": 66
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 296,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 296,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 296,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 296,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 296,
                                                "char": 70
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not-equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 297,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 297,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 297,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 297,
                                                        "char": 46
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
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "string",
                                                                                        "value": "<tr><td class='key'>",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 298,
                                                                                        "char": 57
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "keyRequest",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 298,
                                                                                        "char": 70
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 298,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "<\/td><td>",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 298,
                                                                                    "char": 82
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 298,
                                                                                "char": 82
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "value",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 298,
                                                                                "char": 90
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 298,
                                                                            "char": 90
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "<\/td><\/tr>",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 298,
                                                                            "char": 102
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 298,
                                                                        "char": 102
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 298,
                                                                    "char": 102
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 299,
                                                            "char": 21
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
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "string",
                                                                                        "value": "<tr><td class='key'>",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 300,
                                                                                        "char": 57
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "keyRequest",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 300,
                                                                                        "char": 70
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 300,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "<\/td><td>",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 300,
                                                                                    "char": 82
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 300,
                                                                                "char": 82
                                                                            },
                                                                            "right": {
                                                                                "type": "fcall",
                                                                                "name": "print_r",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "value",
                                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                            "line": 300,
                                                                                            "char": 97
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 300,
                                                                                        "char": 97
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "bool",
                                                                                            "value": "true",
                                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                            "line": 300,
                                                                                            "char": 103
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 300,
                                                                                        "char": 103
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 300,
                                                                                "char": 105
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 300,
                                                                            "char": 105
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "<\/td><\/tr>",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 300,
                                                                            "char": 117
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 300,
                                                                        "char": 117
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 300,
                                                                    "char": 117
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 301,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 302,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 303,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 305,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/table><\/div>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 305,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 305,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 310,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<div id='error-tabs-3'><table cellspacing='0' align='center' class='superglobal-detail'>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 310,
                                                "char": 112
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 310,
                                            "char": 112
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 311,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<tr><th>Key<\/th><th>Value<\/th><\/tr>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 311,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 311,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 312,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "blacklist",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Arr",
                                                "dynamic": 0,
                                                "name": "get",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 312,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "blacklist",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 312,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 312,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 312,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "server",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 312,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 312,
                                                        "char": 61
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "empty-array",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 312,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 312,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 312,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 312,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 314,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "_SERVER",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 314,
                                        "char": 45
                                    },
                                    "key": "keyServer",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 315,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "blacklist",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 315,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "strtolower",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "keyServer",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 315,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 315,
                                                                        "char": 65
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 315,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 315,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 315,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 315,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 315,
                                                "char": 69
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
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "<tr><td class='key'>",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 316,
                                                                                "char": 53
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "keyServer",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 316,
                                                                                "char": 65
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 316,
                                                                            "char": 65
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "<\/td><td>",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 316,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 316,
                                                                        "char": 77
                                                                    },
                                                                    "right": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 316,
                                                                            "char": 84
                                                                        },
                                                                        "name": "getVarDump",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "value",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 316,
                                                                                    "char": 101
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 316,
                                                                                "char": 101
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 316,
                                                                        "char": 103
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 316,
                                                                    "char": 103
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "<\/td><\/tr>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 316,
                                                                    "char": 115
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 316,
                                                                "char": 115
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 316,
                                                            "char": 115
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 317,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 318,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 320,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/table><\/div>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 320,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 320,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 325,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<div id='error-tabs-4'><table cellspacing='0' align='center' class='superglobal-detail'>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 325,
                                                "char": 112
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 325,
                                            "char": 112
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 326,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<tr><th>#<\/th><th>Path<\/th><\/tr>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 326,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 326,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 328,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_included_files",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 328,
                                        "char": 56
                                    },
                                    "key": "keyFile",
                                    "value": "value",
                                    "reverse": 0,
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
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "<tr><td>",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 329,
                                                                        "char": 37
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "keyFile",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 329,
                                                                        "char": 47
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 329,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "<\/th><td>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 329,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 329,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 329,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 329,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "<\/td><\/tr>",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 329,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 329,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 329,
                                                    "char": 79
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 330,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 332,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/table><\/div>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 332,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 332,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 337,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<div id='error-tabs-5'><table cellspacing='0' align='center' class='superglobal-detail'>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 337,
                                                "char": 112
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 337,
                                            "char": 112
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 338,
                                    "char": 15
                                },
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
                                                        "type": "string",
                                                        "value": "<tr><th colspan='2'>Memory<\/th><\/tr><tr><td>Usage<\/td><td>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 338,
                                                        "char": 83
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "memory_get_usage",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 338,
                                                                    "char": 106
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 338,
                                                                "char": 106
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 338,
                                                        "char": 108
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 338,
                                                    "char": 108
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "<\/td><\/tr>",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 338,
                                                    "char": 120
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 338,
                                                "char": 120
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 338,
                                            "char": 120
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 339,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/table><\/div>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 339,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 339,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 344,
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
                                                "value": "dataVars",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 344,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 344,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 344,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 344,
                                        "char": 41
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
                                                        "type": "string",
                                                        "value": "<div id='error-tabs-6'><table cellspacing='0' align='center' class='superglobal-detail'>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 345,
                                                        "char": 116
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 345,
                                                    "char": 116
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 346,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "<tr><th>Key<\/th><th>Value<\/th><\/tr>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 346,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 346,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 348,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "dataVars",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 348,
                                                "char": 49
                                            },
                                            "key": "keyVar",
                                            "value": "dataVar",
                                            "reverse": 0,
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
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "<tr><td class='key'>",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 349,
                                                                                "char": 53
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "keyVar",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 349,
                                                                                "char": 62
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 349,
                                                                            "char": 62
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "<\/td><td>",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 349,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 349,
                                                                        "char": 74
                                                                    },
                                                                    "right": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 349,
                                                                            "char": 81
                                                                        },
                                                                        "name": "getVarDump",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "dataVar",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 349,
                                                                                        "char": 100
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "int",
                                                                                        "value": "0",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 349,
                                                                                        "char": 102
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 349,
                                                                                    "char": 103
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 349,
                                                                                "char": 103
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 349,
                                                                        "char": 105
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 349,
                                                                    "char": 105
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "<\/td><\/tr>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 349,
                                                                    "char": 117
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 349,
                                                                "char": 117
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 349,
                                                            "char": 117
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 350,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 352,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "<\/table><\/div>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 352,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 352,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 353,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 355,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "string",
                                                "value": "<\/div>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 355,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 355,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 356,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 361,
                            "char": 11
                        },
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
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 361,
                                                "char": 25
                                            },
                                            "name": "getJsSources",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 361,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/div><\/body><\/html>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 361,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 361,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 361,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 366,
                            "char": 12
                        },
                        {
                            "type": "echo",
                            "expressions": [
                                {
                                    "type": "variable",
                                    "value": "html",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 366,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 371,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "isActive",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 371,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 371,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 373,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 373,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 374,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles uncaught exceptions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 193,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 193,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 192,
                    "last-line": 378,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "onUncaughtLowSeverity",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "severity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 379,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 379,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 379,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "line",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 379,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 379,
                            "char": 81
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "bitwise_and",
                                    "left": {
                                        "type": "fcall",
                                        "name": "error_reporting",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 381,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "severity",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 381,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 381,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 381,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "ErrorException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 382,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 382,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 382,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 382,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "severity",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 382,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 382,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 382,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 382,
                                                "char": 64
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "line",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 382,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 382,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 382,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 383,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 384,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Throws an exception when a notice or warning is raised\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 380,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 379,
                    "last-line": 388,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBlacklist",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "blacklist",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 389,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "area",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 391,
                                    "char": 17
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 391,
                                    "char": 25
                                },
                                {
                                    "variable": "subArray",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 391,
                                    "char": 35
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 391,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 393,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "area",
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
                                                    "value": "blacklist",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 393,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 393,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "request",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 393,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 393,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 393,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 393,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 393,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 393,
                                    "char": 56
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "subArray",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 394,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 394,
                                    "char": 26
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 395,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 395,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 397,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "area",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 397,
                                "char": 27
                            },
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 398,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 398,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 398,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 398,
                                            "char": 52
                                        },
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "subArray",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 399,
                                                    "char": 31
                                                }
                                            ],
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 399,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 399,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 400,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 402,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "result",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "request",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 402,
                                            "char": 27
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "subArray",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 402,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 402,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "area",
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
                                                    "value": "blacklist",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 403,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 403,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 403,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 403,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 403,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 403,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 403,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 403,
                                    "char": 64
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "subArray",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 404,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 404,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 406,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "area",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 406,
                                "char": 27
                            },
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 407,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 407,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 407,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 407,
                                            "char": 52
                                        },
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "subArray",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 408,
                                                    "char": 31
                                                }
                                            ],
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 408,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 408,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 409,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 411,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "result",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 411,
                                            "char": 26
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "subArray",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 411,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 411,
                                    "char": 38
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "blacklist",
                                    "expr": {
                                        "type": "variable",
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 412,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 412,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 414,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 414,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 415,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if files the exception's backtrace must be showed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 390,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 390,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 390,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 389,
                    "last-line": 419,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setShowBackTrace",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "showBackTrace",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 420,
                            "char": 56
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
                                    "property": "showBackTrace",
                                    "expr": {
                                        "type": "variable",
                                        "value": "showBackTrace",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 422,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 422,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 424,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 424,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 425,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if files the exception's backtrace must be showed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 421,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 421,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 421,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 420,
                    "last-line": 430,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setShowFileFragment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "showFileFragment",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 431,
                            "char": 62
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
                                    "property": "showFileFragment",
                                    "expr": {
                                        "type": "variable",
                                        "value": "showFileFragment",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 433,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 433,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 435,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 435,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 436,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if files must be completely opened and showed in the output\n     * or just the fragment related to the exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 432,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 432,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 432,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 431,
                    "last-line": 440,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setShowFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "showFiles",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 441,
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
                                    "property": "showFiles",
                                    "expr": {
                                        "type": "variable",
                                        "value": "showFiles",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 443,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 443,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 445,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 445,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 446,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set if files part of the backtrace must be shown in the output\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 442,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 442,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 442,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 441,
                    "last-line": 450,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 451,
                            "char": 39
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
                                    "property": "uri",
                                    "expr": {
                                        "type": "variable",
                                        "value": "uri",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 453,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 453,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 455,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 455,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 456,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Change the base URI for static resources\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Debug",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 452,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 452,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 452,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 451,
                    "last-line": 460,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "escapeString",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 461,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 463,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 463,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 463,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 463,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "htmlentities",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "str_replace",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "\\n",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 465,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 465,
                                                            "char": 31
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "\\\\n",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 465,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 465,
                                                            "char": 36
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 465,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 465,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 465,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 465,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "ENT_COMPAT",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 466,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 466,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "utf-8",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 468,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 468,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 468,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 469,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 471,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 471,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 472,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escapes a string with htmlentities\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 462,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 462,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 461,
                    "last-line": 476,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getArrayDump",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "argument",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 477,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "n",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 477,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 477,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "numberArguments",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 479,
                                    "char": 28
                                },
                                {
                                    "variable": "dump",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 479,
                                    "char": 34
                                },
                                {
                                    "variable": "varDump",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 479,
                                    "char": 43
                                },
                                {
                                    "variable": "k",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 479,
                                    "char": 46
                                },
                                {
                                    "variable": "v",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 479,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 481,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "numberArguments",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "argument",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 481,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 481,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 481,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 481,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 483,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "greater-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "n",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 483,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "3",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 483,
                                        "char": 19
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 483,
                                    "char": 19
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "numberArguments",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 483,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 483,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 483,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 483,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 484,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 485,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 487,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater-equal",
                                "left": {
                                    "type": "variable",
                                    "value": "numberArguments",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 487,
                                    "char": 28
                                },
                                "right": {
                                    "type": "int",
                                    "value": "10",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 487,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 487,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "numberArguments",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 488,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 489,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 491,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dump",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 491,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 491,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 493,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "argument",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 493,
                                "char": 30
                            },
                            "key": "k",
                            "value": "v",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "v",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 494,
                                            "char": 19
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 494,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 494,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "varDump",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "(empty string)",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 495,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 495,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 496,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "is_scalar",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "v",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 496,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 496,
                                                        "char": 33
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 496,
                                                "char": 35
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "varDump",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 497,
                                                                    "char": 36
                                                                },
                                                                "name": "escapeString",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "v",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 497,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 497,
                                                                        "char": 51
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 497,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 497,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 498,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 498,
                                            "char": 20
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "v",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 498,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 498,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 498,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 498,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "varDump",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "Array(",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 499,
                                                                        "char": 38
                                                                    },
                                                                    "right": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 499,
                                                                            "char": 45
                                                                        },
                                                                        "name": "getArrayDump",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "v",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 499,
                                                                                    "char": 60
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 499,
                                                                                "char": 60
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "add",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "n",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 499,
                                                                                        "char": 64
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "int",
                                                                                        "value": "1",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 499,
                                                                                        "char": 67
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 499,
                                                                                    "char": 67
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 499,
                                                                                "char": 67
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 499,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 499,
                                                                    "char": 69
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": ")",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 499,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 499,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 499,
                                                            "char": 72
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 500,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 500,
                                            "char": 20
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "v",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 500,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 500,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 500,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 500,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "varDump",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "Object(",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 501,
                                                                        "char": 39
                                                                    },
                                                                    "right": {
                                                                        "type": "fcall",
                                                                        "name": "get_class",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "v",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 501,
                                                                                    "char": 52
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 501,
                                                                                "char": 52
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 501,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 501,
                                                                    "char": 54
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": ")",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 501,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 501,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 501,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 502,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 502,
                                            "char": 20
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "v",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 502,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 502,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 502,
                                                "char": 33
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "varDump",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "null",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 503,
                                                                "char": 35
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 503,
                                                            "char": 35
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 504,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 504,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "varDump",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "v",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 505,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 505,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 506,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 508,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "dump",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "[",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 508,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "k",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 508,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 508,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "] =&gt; ",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 508,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 508,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "varDump",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 508,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 508,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 508,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 509,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 511,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "join",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": ", ",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 511,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 511,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "dump",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 511,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 511,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 511,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 512,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Produces a recursive representation of an array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 477,
                                "char": 71
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 478,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 478,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 477,
                    "last-line": 516,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getVarDump",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "variable",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 517,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 519,
                                    "char": 22
                                },
                                {
                                    "variable": "dumpedObject",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 519,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 521,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "variable",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 521,
                                    "char": 22
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 521,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 521,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 522,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 523,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 525,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "variable",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 525,
                                    "char": 23
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 525,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 525,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 526,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 527,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 532,
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
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 532,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 532,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 532,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 532,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 533,
                                            "char": 25
                                        },
                                        "name": "escapeString",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "variable",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 533,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 533,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 533,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 534,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 539,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_scalar",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 539,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 539,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 539,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 540,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 541,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 546,
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
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 546,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 546,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 546,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 546,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "className",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "get_class",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "variable",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 547,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 547,
                                                        "char": 47
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 547,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 547,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 553,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "method_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "variable",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 553,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 553,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "dump",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 553,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 553,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 553,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "dumpedObject",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "variable",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 554,
                                                            "char": 45
                                                        },
                                                        "name": "dump",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 554,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 554,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 560,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Object(",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 560,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "className",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 560,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 560,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ": ",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 560,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 560,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 560,
                                                            "char": 57
                                                        },
                                                        "name": "getArrayDump",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "dumpedObject",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 560,
                                                                    "char": 83
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 560,
                                                                "char": 83
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 560,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 560,
                                                    "char": 85
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 560,
                                                    "char": 88
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 560,
                                                "char": 88
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 561,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "Object(",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 566,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 566,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 566,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 566,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 566,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 567,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 568,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 573,
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
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 573,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 573,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 573,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 573,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "Array(",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 574,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 574,
                                                    "char": 34
                                                },
                                                "name": "getArrayDump",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "variable",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 574,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 574,
                                                        "char": 56
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 574,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 574,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 574,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 574,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 575,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 580,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "variable",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 580,
                                    "char": 23
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 580,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 580,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "null",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 581,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 582,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 587,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "gettype",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 587,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 587,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 587,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 588,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Produces an string representation of a variable\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 518,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 518,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 517,
                    "last-line": 593,
                    "char": 22
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "showTraceItem",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "n",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 594,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "trace",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 594,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 596,
                                    "char": 22
                                },
                                {
                                    "variable": "prepareInternalClass",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 596,
                                    "char": 44
                                },
                                {
                                    "variable": "preparedFunctionName",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 596,
                                    "char": 66
                                },
                                {
                                    "variable": "html",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 596,
                                    "char": 72
                                },
                                {
                                    "variable": "classReflection",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 597,
                                    "char": 28
                                },
                                {
                                    "variable": "prepareUriClass",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 597,
                                    "char": 45
                                },
                                {
                                    "variable": "functionName",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 597,
                                    "char": 59
                                },
                                {
                                    "variable": "functionReflection",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 597,
                                    "char": 79
                                },
                                {
                                    "variable": "traceArgs",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 22
                                },
                                {
                                    "variable": "arguments",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 33
                                },
                                {
                                    "variable": "argument",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 43
                                },
                                {
                                    "variable": "filez",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 50
                                },
                                {
                                    "variable": "line",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 56
                                },
                                {
                                    "variable": "showFiles",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 67
                                },
                                {
                                    "variable": "lines",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 598,
                                    "char": 74
                                },
                                {
                                    "variable": "numberLines",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 599,
                                    "char": 24
                                },
                                {
                                    "variable": "showFileFragment",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 599,
                                    "char": 42
                                },
                                {
                                    "variable": "firstLine",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 599,
                                    "char": 53
                                },
                                {
                                    "variable": "lastLine",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 599,
                                    "char": 63
                                },
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 599,
                                    "char": 66
                                },
                                {
                                    "variable": "linePosition",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 599,
                                    "char": 80
                                },
                                {
                                    "variable": "currentLine",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 600,
                                    "char": 24
                                },
                                {
                                    "variable": "classNameWithLink",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 600,
                                    "char": 43
                                },
                                {
                                    "variable": "functionNameWithLink",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 600,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 605,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<tr><td align='right' valign='top' class='error-number'>#",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 605,
                                                "char": 78
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "n",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 605,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 605,
                                            "char": 82
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/td><td>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 605,
                                            "char": 93
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 605,
                                        "char": 93
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 605,
                                    "char": 93
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 607,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "className",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 607,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "trace",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 607,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "class",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 607,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 607,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 607,
                                "char": 42
                            },
                            "statements": [
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
                                                    "value": "\/^Phalcon\/",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 612,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 612,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 612,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 612,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 612,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "prepareUriClass",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\\\\",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 616,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 616,
                                                                "char": 53
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "_",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 616,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 616,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 616,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 616,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 616,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 616,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 621,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "classNameWithLink",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "<a target='_new' href='https:\/\/docs.phalconphp.com\/4.0\/en\/api\/",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 621,
                                                                        "char": 104
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "prepareUriClass",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 621,
                                                                        "char": 122
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 621,
                                                                    "char": 122
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "'>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 621,
                                                                    "char": 127
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 621,
                                                                "char": 127
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "className",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 621,
                                                                "char": 139
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 621,
                                                            "char": 139
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "<\/a>",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 621,
                                                            "char": 145
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 621,
                                                        "char": 145
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 621,
                                                    "char": 145
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 622,
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
                                                    "variable": "classReflection",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "ReflectionClass",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 623,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 623,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 623,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 623,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 628,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "classReflection",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 628,
                                                    "char": 36
                                                },
                                                "name": "isInternal",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 628,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "prepareInternalClass",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_replace",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "_",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 630,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 630,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "-",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 631,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 631,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "fcall",
                                                                            "name": "strtolower",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "className",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 632,
                                                                                        "char": 45
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 632,
                                                                                    "char": 45
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 633,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 633,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 633,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 633,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 638,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "classNameWithLink",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "<a target='_new' href='https:\/\/secure.php.net\/manual\/en\/class.",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 638,
                                                                                "char": 108
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "prepareInternalClass",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 638,
                                                                                "char": 131
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 638,
                                                                            "char": 131
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ".php'>",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 638,
                                                                            "char": 140
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 638,
                                                                        "char": 140
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "className",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 638,
                                                                        "char": 152
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 638,
                                                                    "char": 152
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "<\/a>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 638,
                                                                    "char": 158
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 638,
                                                                "char": 158
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 638,
                                                            "char": 158
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 639,
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
                                                            "variable": "classNameWithLink",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "className",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 640,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 640,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 641,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 642,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 644,
                                    "char": 15
                                },
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
                                                        "type": "string",
                                                        "value": "<span class='error-class'>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 644,
                                                        "char": 51
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "classNameWithLink",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 644,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 644,
                                                    "char": 71
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "<\/span>",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 644,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 644,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 644,
                                            "char": 80
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 649,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "html",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "trace",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 649,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 649,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 649,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 649,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 650,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 655,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "functionName",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "trace",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 655,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "function",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 655,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 655,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 655,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 657,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "trace",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 657,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "class",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 657,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 657,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 657,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "functionNameWithLink",
                                            "expr": {
                                                "type": "variable",
                                                "value": "functionName",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 658,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 658,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 659,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "functionName",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 663,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 663,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 663,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "functionReflection",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "ReflectionFunction",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "functionName",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 664,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 664,
                                                                "char": 77
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 664,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 664,
                                                    "char": 78
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 669,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "functionReflection",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 669,
                                                    "char": 39
                                                },
                                                "name": "isInternal",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 669,
                                                "char": 53
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "preparedFunctionName",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_replace",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "_",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 674,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 674,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "-",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 675,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 675,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "functionName",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 677,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 677,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 677,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 677,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 679,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "functionNameWithLink",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "<a target='_new' href='https:\/\/secure.php.net\/manual\/en\/function.",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 679,
                                                                                "char": 114
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "preparedFunctionName",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 679,
                                                                                "char": 137
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 679,
                                                                            "char": 137
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ".php'>",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 679,
                                                                            "char": 146
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 679,
                                                                        "char": 146
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "functionName",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 679,
                                                                        "char": 161
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 679,
                                                                    "char": 161
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "<\/a>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 679,
                                                                    "char": 167
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 679,
                                                                "char": 167
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 679,
                                                            "char": 167
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 680,
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
                                                            "variable": "functionNameWithLink",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "functionName",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 681,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 681,
                                                            "char": 60
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 682,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 683,
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
                                                    "variable": "functionNameWithLink",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "functionName",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 684,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 684,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 685,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 686,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 688,
                            "char": 11
                        },
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
                                                "type": "string",
                                                "value": "<span class='error-function'>",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 688,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "functionNameWithLink",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 688,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 688,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/span>",
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 688,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 688,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 688,
                                    "char": 82
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 693,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "traceArgs",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 693,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "trace",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 693,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "args",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 693,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 693,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 693,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "arguments",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 694,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 694,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 696,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "traceArgs",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 696,
                                        "char": 39
                                    },
                                    "value": "argument",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "arguments",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "<span class='error-parameter'>",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 701,
                                                                "char": 66
                                                            },
                                                            "right": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 701,
                                                                    "char": 73
                                                                },
                                                                "name": "getVarDump",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "argument",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 701,
                                                                            "char": 93
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 701,
                                                                        "char": 93
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 701,
                                                                "char": 95
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 701,
                                                            "char": 95
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "<\/span>",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 701,
                                                            "char": 104
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 701,
                                                        "char": 104
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 701,
                                                    "char": 104
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 702,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 707,
                                    "char": 15
                                },
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
                                                        "type": "string",
                                                        "value": "(",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 707,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "join",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": ", ",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 707,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 707,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "arguments",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 707,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 707,
                                                                "char": 46
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 707,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 707,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 707,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 707,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 707,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 708,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 714,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "filez",
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 714,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "trace",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 714,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 714,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 714,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 714,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "line",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "trace",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 715,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "line",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 715,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 715,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 715,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 715,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 720,
                                    "char": 15
                                },
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
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "<br\/><div class='error-file'>",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 720,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "filez",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 720,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 720,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": " (",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 720,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 720,
                                                        "char": 67
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "line",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 720,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 720,
                                                    "char": 74
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")<\/div>",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 720,
                                                    "char": 83
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 720,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 720,
                                            "char": 83
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 722,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "showFiles",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 722,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "showFiles",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 722,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 722,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 722,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 727,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "showFiles",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 727,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "lines",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "file",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filez",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 732,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 732,
                                                                "char": 39
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 732,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 732,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 734,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "numberLines",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "count",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "lines",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 734,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 734,
                                                                "char": 46
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 734,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 734,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 735,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "showFileFragment",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 735,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "showFileFragment",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 735,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 735,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 735,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 741,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "showFileFragment",
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 741,
                                                "char": 37
                                            },
                                            "statements": [
                                                {
                                                    "type": "declare",
                                                    "data-type": "int",
                                                    "variables": [
                                                        {
                                                            "variable": "beforeLine",
                                                            "expr": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "line",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 745,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "7",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 745,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 745,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 745,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 750,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "less",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "beforeLine",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 750,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 750,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 750,
                                                        "char": 39
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "firstLine",
                                                                    "expr": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 751,
                                                                        "char": 42
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 751,
                                                                    "char": 42
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 752,
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
                                                                    "variable": "firstLine",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "beforeLine",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 753,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 753,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 754,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 759,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "declare",
                                                    "data-type": "int",
                                                    "variables": [
                                                        {
                                                            "variable": "afterLine",
                                                            "expr": {
                                                                "type": "add",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "line",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 759,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "5",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 759,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 759,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 759,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 764,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "greater",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "afterLine",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 764,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "numberLines",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 764,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 764,
                                                        "char": 48
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "lastLine",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "numberLines",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 765,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 765,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 766,
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
                                                                    "variable": "lastLine",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "afterLine",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 767,
                                                                        "char": 49
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 767,
                                                                    "char": 49
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 768,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 770,
                                                    "char": 23
                                                },
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
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "string",
                                                                                        "value": "<pre class='prettyprint highlight:",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 770,
                                                                                        "char": 67
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "firstLine",
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 770,
                                                                                        "char": 79
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 770,
                                                                                    "char": 79
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": ":",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 770,
                                                                                    "char": 83
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 770,
                                                                                "char": 83
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "line",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 770,
                                                                                "char": 90
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 770,
                                                                            "char": 90
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": " linenums:",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 770,
                                                                            "char": 103
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 770,
                                                                        "char": 103
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "firstLine",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 770,
                                                                        "char": 115
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 770,
                                                                    "char": 115
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "'>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 770,
                                                                    "char": 119
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 770,
                                                                "char": 119
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 770,
                                                            "char": 119
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 771,
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
                                                            "variable": "firstLine",
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 772,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 772,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 773,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "lastLine",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "numberLines",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 773,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 773,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 774,
                                                    "char": 23
                                                },
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
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "<pre class='prettyprint highlight:",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 774,
                                                                                "char": 67
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "firstLine",
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 774,
                                                                                "char": 79
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 774,
                                                                            "char": 79
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": ":",
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 774,
                                                                            "char": 83
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 774,
                                                                        "char": 83
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "line",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 774,
                                                                        "char": 90
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 774,
                                                                    "char": 90
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": " linenums error-scroll'>",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 774,
                                                                    "char": 116
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 774,
                                                                "char": 116
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 774,
                                                            "char": 116
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 775,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 777,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "i",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "firstLine",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 777,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 777,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 779,
                                            "char": 21
                                        },
                                        {
                                            "type": "while",
                                            "expr": {
                                                "type": "less-equal",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "i",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 779,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "lastLine",
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 779,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                "line": 779,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "linePosition",
                                                            "expr": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "i",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 783,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 783,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 783,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 783,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 788,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "currentLine",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "lines",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 788,
                                                                    "char": 44
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "linePosition",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 788,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 788,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 788,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 793,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "showFileFragment",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 793,
                                                        "char": 41
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "i",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 794,
                                                                    "char": 31
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "firstLine",
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 794,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 794,
                                                                "char": 43
                                                            },
                                                            "statements": [
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
                                                                                    "value": "#\\\\*\\\\\/#",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 795,
                                                                                    "char": 51
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 795,
                                                                                "char": 51
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "fcall",
                                                                                    "name": "rtrim",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "variable",
                                                                                                "value": "currentLine",
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 795,
                                                                                                "char": 70
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                            "line": 795,
                                                                                            "char": 70
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 795,
                                                                                    "char": 71
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 795,
                                                                                "char": 71
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 795,
                                                                        "char": 73
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "currentLine",
                                                                                    "expr": {
                                                                                        "type": "fcall",
                                                                                        "name": "str_replace",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": "* \/",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                    "line": 797,
                                                                                                    "char": 40
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 797,
                                                                                                "char": 40
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": " ",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                    "line": 798,
                                                                                                    "char": 38
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 798,
                                                                                                "char": 38
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "variable",
                                                                                                    "value": "currentLine",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                    "line": 800,
                                                                                                    "char": 33
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 800,
                                                                                                "char": 33
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                        "line": 800,
                                                                                        "char": 34
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 800,
                                                                                    "char": 34
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                            "line": 801,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 802,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 803,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 809,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "currentLine",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 809,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "\\n",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 809,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 809,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "currentLine",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 809,
                                                                "char": 58
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "\\r\\n",
                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                "line": 809,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 809,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 809,
                                                        "char": 65
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
                                                                        "type": "string",
                                                                        "value": "&nbsp;\\n",
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 810,
                                                                        "char": 44
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 810,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 811,
                                                            "char": 21
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
                                                                        "type": "fcall",
                                                                        "name": "htmlentities",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "fcall",
                                                                                    "name": "str_replace",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "string",
                                                                                                "value": "\\t",
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 817,
                                                                                                "char": 43
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                            "line": 817,
                                                                                            "char": 43
                                                                                        },
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "string",
                                                                                                "value": "  ",
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 817,
                                                                                                "char": 47
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                            "line": 817,
                                                                                            "char": 47
                                                                                        },
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "variable",
                                                                                                "value": "currentLine",
                                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                                "line": 817,
                                                                                                "char": 60
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                            "line": 817,
                                                                                            "char": 60
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 817,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 817,
                                                                                "char": 61
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "constant",
                                                                                    "value": "ENT_COMPAT",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 818,
                                                                                    "char": 39
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 818,
                                                                                "char": 39
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "UTF-8",
                                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                    "line": 820,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                                "line": 820,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                        "line": 820,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                                    "line": 820,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 821,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 823,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "incr",
                                                            "variable": "i",
                                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                            "line": 823,
                                                            "char": 28
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 824,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 826,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "html",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "<\/pre>",
                                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                        "line": 826,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                                    "line": 826,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                            "line": 827,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 828,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 830,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "html",
                                    "expr": {
                                        "type": "string",
                                        "value": "<\/td><\/tr>",
                                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                        "line": 830,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                    "line": 830,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 832,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "html",
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 832,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Debug\/Debug.zep",
                            "line": 833,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Shows a backtrace item\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Debug.zep",
                                "line": 595,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Debug.zep",
                        "line": 595,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Debug.zep",
                    "line": 594,
                    "last-line": 834,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Debug\/Debug.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Debug\/Debug.zep",
        "line": 23,
        "char": 5
    }
]