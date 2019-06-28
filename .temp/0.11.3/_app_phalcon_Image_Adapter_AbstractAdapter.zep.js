[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Image\\Adapter",
        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image",
                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 18
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image\\Exception",
                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Image\\Adapter\n *\n * All image adapters must use this class\n *",
        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
        "line": 21,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractAdapter",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "AdapterInterface",
                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                "line": 22,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "checked",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 23,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 25,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "file",
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 31,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "height",
                    "docblock": "**\n     * Image height\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 32,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 34,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "image",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 34,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "mime",
                    "docblock": "**\n     * Image mime type\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 40,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 42,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "realpath",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 42,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * Image type\n     *\n     * Driver dependent\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 51,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 57,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "width",
                    "docblock": "**\n     * Image width\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 58,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 62,
                    "char": 7
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "background",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "color",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 63,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "100",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 63,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 63,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "colors",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 65,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 67,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 67,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 67,
                                                "char": 24
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 67,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 67,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 67,
                                    "char": 31
                                },
                                "right": {
                                    "type": "identical",
                                    "left": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 67,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 67,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 67,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 67,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 67,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 67,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 67,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "#",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 67,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 67,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 67,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 68,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 68,
                                                        "char": 37
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 68,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 68,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 68,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 68,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 69,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 71,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "strlen",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "color",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 71,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 71,
                                            "char": 24
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 71,
                                    "char": 28
                                },
                                "right": {
                                    "type": "int",
                                    "value": "3",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 71,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 71,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "preg_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\/.\/",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 72,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 72,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "$0$0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 72,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 72,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 72,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 72,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 72,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 72,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 75,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "colors",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_map",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "hexdec",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 76,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 76,
                                                "char": 19
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "str_split",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "color",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 77,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 77,
                                                            "char": 28
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "int",
                                                                "value": "2",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 77,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 77,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 78,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 78,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 78,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 78,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 80,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 80,
                                    "char": 14
                                },
                                "name": "processBackground",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "colors",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 80,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 80,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 80,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 80,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "colors",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 80,
                                                "char": 52
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 80,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 80,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 80,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "colors",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 80,
                                                "char": 63
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 80,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 80,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 80,
                                        "char": 66
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 80,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 80,
                                        "char": 75
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 80,
                                "char": 76
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 82,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 82,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Set the background color of an image\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 64,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 64,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 63,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "blur",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "radius",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 88,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "radius",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 90,
                                    "char": 19
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 90,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 90,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "radius",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 91,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 91,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "radius",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 92,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 92,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 92,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "radius",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "100",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 93,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 93,
                                                    "char": 29
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 94,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 96,
                                    "char": 12
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 96,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 96,
                                    "char": 14
                                },
                                "name": "processBlur",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "radius",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 96,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 96,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 96,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 98,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Blur image\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 89,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 89,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 88,
                    "last-line": 103,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "crop",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 104,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 104,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 104,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 104,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 104,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 104,
                            "char": 87
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_null",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 106,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 106,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 106,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "offsetX",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "div",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 107,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "width",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 107,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 107,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 107,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 107,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 107,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "2",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 107,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 107,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 107,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 107,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 108,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 109,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 109,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 109,
                                        "char": 28
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetX",
                                                    "expr": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 110,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "width",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 110,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 110,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 110,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 110,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetX",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 110,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 110,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 110,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 111,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 113,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 113,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 113,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 113,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 113,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 113,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetX",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 114,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 114,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 114,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 114,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 114,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 115,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 116,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 118,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_null",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 118,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 118,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 118,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "offsetY",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "div",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 119,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "height",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 119,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 119,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 119,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 119,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 119,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "2",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 119,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 119,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 119,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 119,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 121,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 121,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 121,
                                        "char": 28
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetY",
                                                    "expr": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 122,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "height",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 122,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 122,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 122,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 122,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetY",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 122,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 122,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 122,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 123,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 125,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 125,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 125,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 125,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 125,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 125,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetY",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 126,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 126,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 126,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 126,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 126,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 127,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 128,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 130,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "width",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 130,
                                    "char": 18
                                },
                                "right": {
                                    "type": "list",
                                    "left": {
                                        "type": "sub",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 130,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 130,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 130,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 130,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 130,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 130,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 130,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "width",
                                            "expr": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 131,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 131,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 131,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "offsetX",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 131,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 131,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 131,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 132,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 134,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 134,
                                    "char": 19
                                },
                                "right": {
                                    "type": "list",
                                    "left": {
                                        "type": "sub",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 134,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 134,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 134,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 134,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 134,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 134,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 134,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "height",
                                            "expr": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 135,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 135,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 135,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "offsetY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 135,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 135,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 135,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 136,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 138,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 138,
                                    "char": 14
                                },
                                "name": "processCrop",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 138,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 138,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 138,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 138,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 138,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 138,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 138,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 138,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 138,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 140,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 140,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 141,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Crop an image to the given size\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 105,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 105,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 105,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 104,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "flip",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "direction",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 146,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "direction",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 148,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 148,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HORIZONTAL",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 148,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 148,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 148,
                                    "char": 44
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "direction",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 148,
                                        "char": 57
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 148,
                                            "char": 75
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "VERTICAL",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 148,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 148,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 148,
                                    "char": 75
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 148,
                                "char": 75
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "direction",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 149,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "HORIZONTAL",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 149,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 149,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 149,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 150,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 152,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 152,
                                    "char": 14
                                },
                                "name": "processFlip",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "direction",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 152,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 152,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 152,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 154,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 154,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 155,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Flip the image along the horizontal or vertical axis\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 147,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 147,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 147,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 146,
                    "last-line": 166,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "liquidRescale",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 167,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 167,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "deltaX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 167,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 167,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "rigidity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 167,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 167,
                            "char": 90
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 169,
                                    "char": 14
                                },
                                "name": "processLiquidRescale",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 169,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 169,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 169,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 169,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "deltaX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 169,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 169,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "rigidity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 169,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 169,
                                        "char": 69
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 169,
                                "char": 70
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 171,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 171,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 172,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * This method scales the images using liquid rescaling method. Only support\n     * Imagick\n     *\n     * @param int $width   new width\n     * @param int $height  new height\n     * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.\n     * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 168,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 168,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 168,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 167,
                    "last-line": 176,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "mask",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "watermark",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 177,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 177,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 179,
                                    "char": 14
                                },
                                "name": "processMask",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "watermark",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 179,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 179,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 179,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 181,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 181,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 182,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Composite one image onto another\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 178,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 178,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 178,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 177,
                    "last-line": 186,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "pixelate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "amount",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 187,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "amount",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 189,
                                    "char": 19
                                },
                                "right": {
                                    "type": "int",
                                    "value": "2",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 189,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 189,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "amount",
                                            "expr": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 190,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 190,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 191,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 193,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 193,
                                    "char": 14
                                },
                                "name": "processPixelate",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "amount",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 193,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 193,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 193,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 195,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 195,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 196,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Pixelate image\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 188,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 188,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 188,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 187,
                    "last-line": 200,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reflection",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 201,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "100",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 201,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 201,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "fadeIn",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 201,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 201,
                            "char": 82
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "less-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "height",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 203,
                                        "char": 19
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 203,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 203,
                                    "char": 24
                                },
                                "right": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "height",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 203,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 203,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 203,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 203,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 203,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 203,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "height",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 204,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 204,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 204,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 204,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 204,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 205,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 207,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "opacity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 207,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 207,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 207,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "opacity",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 208,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 208,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 209,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 209,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 209,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 209,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "opacity",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "100",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 210,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 210,
                                                    "char": 30
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 211,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 213,
                                    "char": 12
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 213,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 213,
                                    "char": 14
                                },
                                "name": "processReflection",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 213,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 213,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 213,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 213,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fadeIn",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 213,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 213,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 213,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 215,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 215,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 216,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Add a reflection to an image\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 202,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 202,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 202,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 201,
                    "last-line": 220,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "ext",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 221,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 221,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "quality",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "100",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 221,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 221,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "ext",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 223,
                                    "char": 17
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 223,
                                "char": 17
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ext",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "pathinfo",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 224,
                                                                    "char": 46
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "file",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 224,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 224,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 224,
                                                            "char": 51
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "constant",
                                                                "value": "PATHINFO_EXTENSION",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 224,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 224,
                                                            "char": 71
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 224,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 224,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 224,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 225,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 227,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "ext",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 227,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 227,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ext",
                                            "expr": {
                                                "type": "string",
                                                "value": "png",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 228,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 228,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 229,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 231,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "quality",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 231,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 231,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 231,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "quality",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 232,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 232,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 233,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "quality",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 233,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 233,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 233,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "quality",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "100",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 234,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 234,
                                                    "char": 30
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 235,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 237,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 237,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 237,
                                    "char": 21
                                },
                                "name": "processRender",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ext",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 237,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 237,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "quality",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 237,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 237,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 237,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 238,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Render the image and return the binary string\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 222,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 222,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 221,
                    "last-line": 242,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "resize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 243,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 243,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 243,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 243,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "master",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "Image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 243,
                                    "char": 89
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "AUTO",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 243,
                                    "char": 89
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 243,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 243,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "ratio",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 245,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 247,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "master",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 247,
                                    "char": 20
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "Image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 247,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "TENSILE",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 247,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 247,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 247,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "or",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 249,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 249,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 249,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 249,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 249,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 249,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 249,
                                        "char": 45
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
                                                            "value": "width and height must be specified",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 250,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 250,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 250,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 251,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 253,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "master",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 254,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 254,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "AUTO",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 254,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 254,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 254,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 256,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 256,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 256,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 256,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 256,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 256,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 256,
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
                                                                    "type": "string",
                                                                    "value": "width and height must be specified",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 257,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 257,
                                                                "char": 75
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 257,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 258,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 260,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "master",
                                                    "expr": {
                                                        "type": "ternary",
                                                        "left": {
                                                            "type": "greater",
                                                            "left": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "div",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 260,
                                                                            "char": 36
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "width",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 260,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 260,
                                                                        "char": 43
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "width",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 260,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 260,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 260,
                                                                "char": 52
                                                            },
                                                            "right": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "div",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 260,
                                                                            "char": 60
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "height",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 260,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 260,
                                                                        "char": 68
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "height",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 260,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 260,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 260,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 260,
                                                            "char": 78
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 260,
                                                                "char": 93
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "WIDTH",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 260,
                                                                "char": 93
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 260,
                                                            "char": 93
                                                        },
                                                        "extra": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 260,
                                                                "char": 108
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "HEIGHT",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 260,
                                                                "char": 108
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 260,
                                                            "char": 108
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 260,
                                                        "char": 108
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 260,
                                                    "char": 108
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 261,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 263,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "master",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 263,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 263,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "INVERSE",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 263,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 263,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 263,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 265,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 265,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 265,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 265,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 265,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 265,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 265,
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
                                                                    "type": "string",
                                                                    "value": "width and height must be specified",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 266,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 266,
                                                                "char": 75
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 266,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 267,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 269,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "master",
                                                    "expr": {
                                                        "type": "ternary",
                                                        "left": {
                                                            "type": "greater",
                                                            "left": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "div",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 269,
                                                                            "char": 36
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "width",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 269,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 269,
                                                                        "char": 43
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "width",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 269,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 269,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 269,
                                                                "char": 52
                                                            },
                                                            "right": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "div",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 269,
                                                                            "char": 60
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "height",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 269,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 269,
                                                                        "char": 68
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "height",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 269,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 269,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 269,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 269,
                                                            "char": 78
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 269,
                                                                "char": 94
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "HEIGHT",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 269,
                                                                "char": 94
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 269,
                                                            "char": 94
                                                        },
                                                        "extra": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 269,
                                                                "char": 108
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "WIDTH",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 269,
                                                                "char": 108
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 269,
                                                            "char": 108
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 269,
                                                        "char": 108
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 269,
                                                    "char": 108
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 270,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 272,
                                    "char": 18
                                },
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "variable",
                                        "value": "master",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 272,
                                        "char": 27
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 274,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "WIDTH",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 274,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 274,
                                                "char": 34
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
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 275,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 275,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 275,
                                                        "char": 40
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
                                                                            "value": "width must be specified",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 276,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 276,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 276,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 277,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 279,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "height",
                                                            "expr": {
                                                                "type": "div",
                                                                "left": {
                                                                    "type": "mul",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 279,
                                                                            "char": 39
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "height",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 279,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 279,
                                                                        "char": 47
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "width",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 279,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 279,
                                                                    "char": 55
                                                                },
                                                                "right": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 279,
                                                                        "char": 62
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "width",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 279,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 279,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 279,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 279,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 281,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 283,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 283,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 283,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "HEIGHT",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 283,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 283,
                                                "char": 35
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
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 284,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 284,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 284,
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
                                                                            "type": "string",
                                                                            "value": "height must be specified",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 285,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 285,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 285,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 286,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 288,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "width",
                                                            "expr": {
                                                                "type": "div",
                                                                "left": {
                                                                    "type": "mul",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 288,
                                                                            "char": 38
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "width",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 288,
                                                                            "char": 45
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 288,
                                                                        "char": 45
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "height",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 288,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 288,
                                                                    "char": 54
                                                                },
                                                                "right": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 288,
                                                                        "char": 61
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "height",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 288,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 288,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 288,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 288,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 290,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 292,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 292,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 292,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PRECISE",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 292,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 292,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "or",
                                                                "left": {
                                                                    "type": "not",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "width",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 293,
                                                                        "char": 42
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 293,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "not",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "height",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 293,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 293,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 293,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 293,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 293,
                                                        "char": 53
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
                                                                            "value": "width and height must be specified",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 296,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 296,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 296,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 297,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 299,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "ratio",
                                                            "expr": {
                                                                "type": "div",
                                                                "left": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 299,
                                                                        "char": 38
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "width",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 299,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 299,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 299,
                                                                        "char": 52
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "height",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 299,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 299,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 299,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 299,
                                                            "char": 59
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 301,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "greater",
                                                        "left": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "div",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "width",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 301,
                                                                    "char": 31
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "height",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 301,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 301,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 301,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ratio",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 301,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 301,
                                                        "char": 49
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "height",
                                                                    "expr": {
                                                                        "type": "div",
                                                                        "left": {
                                                                            "type": "mul",
                                                                            "left": {
                                                                                "type": "property-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                    "line": 302,
                                                                                    "char": 43
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "height",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                    "line": 302,
                                                                                    "char": 51
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 302,
                                                                                "char": 51
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "width",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 302,
                                                                                "char": 59
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 302,
                                                                            "char": 59
                                                                        },
                                                                        "right": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 302,
                                                                                "char": 66
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "width",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 302,
                                                                                "char": 72
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 302,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 302,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 302,
                                                                    "char": 72
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 303,
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
                                                                    "variable": "width",
                                                                    "expr": {
                                                                        "type": "div",
                                                                        "left": {
                                                                            "type": "mul",
                                                                            "left": {
                                                                                "type": "property-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                    "line": 304,
                                                                                    "char": 42
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "width",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                    "line": 304,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 304,
                                                                                "char": 49
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "height",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 304,
                                                                                "char": 58
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 304,
                                                                            "char": 58
                                                                        },
                                                                        "right": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 304,
                                                                                "char": 65
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "height",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 304,
                                                                                "char": 72
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 304,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 304,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 304,
                                                                    "char": 72
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 305,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 307,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 309,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 309,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 309,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "NONE",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 309,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 309,
                                                "char": 33
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "width",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 310,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 310,
                                                        "char": 31
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "width",
                                                                    "expr": {
                                                                        "type": "cast",
                                                                        "left": "int",
                                                                        "right": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 311,
                                                                                "char": 48
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "width",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 311,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 311,
                                                                            "char": 54
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 311,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 311,
                                                                    "char": 54
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 312,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 314,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "height",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 314,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 314,
                                                        "char": 32
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "width",
                                                                    "expr": {
                                                                        "type": "cast",
                                                                        "left": "int",
                                                                        "right": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 315,
                                                                                "char": 48
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "height",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                                "line": 315,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                            "line": 315,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                        "line": 315,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 315,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 316,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 318,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 319,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 319,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 320,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 322,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "width",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "max",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "round",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "width",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 322,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 322,
                                                                "char": 43
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 322,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 322,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 322,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 322,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 322,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 322,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 322,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 323,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "height",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "max",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "round",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "height",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                    "line": 323,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 323,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 323,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 323,
                                                    "char": 45
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 323,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 323,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 323,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 323,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 323,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 325,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 325,
                                    "char": 14
                                },
                                "name": "processResize",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 325,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 325,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 325,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 325,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 325,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 327,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 327,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 328,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Resize the image to the given size\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 244,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 244,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 244,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 243,
                    "last-line": 332,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rotate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "degrees",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 333,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "degrees",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 335,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "180",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 335,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 335,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "degrees",
                                            "expr": {
                                                "type": "mod",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "degrees",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 337,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "360",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 337,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 337,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 337,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 339,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "degrees",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 339,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "180",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 339,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 339,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "sub-assign",
                                                    "variable": "degrees",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "360",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 340,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 340,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 341,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 342,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "degrees",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 343,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "-180",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 343,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 343,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "add-assign",
                                                    "variable": "degrees",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "360",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 344,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 344,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 345,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 346,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 348,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 348,
                                    "char": 14
                                },
                                "name": "processRotate",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "degrees",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 348,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 348,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 348,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 350,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 350,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 351,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Rotate the image by a given amount\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 334,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 334,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 334,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 333,
                    "last-line": 355,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "save",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 356,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 356,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "quality",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "-1",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 356,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 356,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "file",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 358,
                                    "char": 18
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 358,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "file",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 359,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "realpath",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 359,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 359,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 359,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 359,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 360,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 362,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 362,
                                    "char": 14
                                },
                                "name": "processSave",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "file",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 362,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 362,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "quality",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 362,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 362,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 362,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 364,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 364,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 365,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Save the image\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 357,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 357,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 357,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 356,
                    "last-line": 369,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sharpen",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "amount",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 370,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "variable",
                                    "value": "amount",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 372,
                                    "char": 19
                                },
                                "right": {
                                    "type": "int",
                                    "value": "100",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 372,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 372,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "amount",
                                            "expr": {
                                                "type": "int",
                                                "value": "100",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 373,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 373,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 374,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "amount",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 374,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 374,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 374,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "amount",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 375,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 375,
                                                    "char": 27
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 376,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 378,
                                    "char": 12
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 378,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 378,
                                    "char": 14
                                },
                                "name": "processSharpen",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "amount",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 378,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 378,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 378,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 380,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 380,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 381,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Sharpen the image by a given amount\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 371,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 371,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 371,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 370,
                    "last-line": 385,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "text",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 386,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 386,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 79
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "100",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 386,
                                "char": 98
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 98
                        },
                        {
                            "type": "parameter",
                            "name": "color",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "000000",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 386,
                                "char": 121
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 121
                        },
                        {
                            "type": "parameter",
                            "name": "size",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "12",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 386,
                                "char": 136
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 136
                        },
                        {
                            "type": "parameter",
                            "name": "fontfile",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 386,
                                "char": 160
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 386,
                            "char": 160
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "colors",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 388,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 390,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "opacity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 390,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 390,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 390,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "opacity",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 391,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 391,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 392,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 393,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 393,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 393,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "opacity",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "100",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 394,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 394,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 395,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 396,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 398,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 398,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 398,
                                                "char": 24
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 398,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 398,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 398,
                                    "char": 31
                                },
                                "right": {
                                    "type": "identical",
                                    "left": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 398,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 398,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 398,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 398,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 398,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 398,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 398,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "#",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 398,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 398,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 398,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 399,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 399,
                                                        "char": 37
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 399,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 399,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 399,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 399,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 400,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 402,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "strlen",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "color",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 402,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 402,
                                            "char": 24
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 402,
                                    "char": 28
                                },
                                "right": {
                                    "type": "int",
                                    "value": "3",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 402,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 402,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "preg_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\/.\/",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 403,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 403,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "$0$0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 403,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 403,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 403,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 403,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 403,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 403,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 404,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 406,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "colors",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_map",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "hexdec",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 407,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 407,
                                                "char": 19
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "str_split",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "color",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 408,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 408,
                                                            "char": 28
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "int",
                                                                "value": "2",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                                "line": 408,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                            "line": 408,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 409,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 409,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 409,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 409,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 411,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 411,
                                    "char": 14
                                },
                                "name": "processText",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 412,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 412,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 413,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 413,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 414,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 414,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 415,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 415,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "colors",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 416,
                                                "char": 19
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 416,
                                                "char": 21
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 416,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 416,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "colors",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 417,
                                                "char": 19
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 417,
                                                "char": 21
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 417,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 417,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "colors",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 418,
                                                "char": 19
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 418,
                                                "char": 21
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 418,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 418,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "size",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 419,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 419,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fontfile",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 421,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 421,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 421,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 423,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 423,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 424,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Add a text to an image with a specified opacity\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 387,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 387,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 387,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 386,
                    "last-line": 428,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "watermark",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "watermark",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 429,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 429,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 429,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 429,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 429,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 429,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "100",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 429,
                                "char": 112
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 429,
                            "char": 112
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 431,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 433,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tmp",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 433,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 433,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 433,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "watermark",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 433,
                                                "char": 43
                                            },
                                            "name": "getWidth",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 433,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 433,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 433,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 435,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "offsetX",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 435,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 435,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 435,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "offsetX",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 436,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 436,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 437,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 437,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "tmp",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 437,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 437,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetX",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "tmp",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 438,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 438,
                                                    "char": 30
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 439,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 441,
                                    "char": 11
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 441,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tmp",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 441,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 441,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 441,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "watermark",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 441,
                                                "char": 44
                                            },
                                            "name": "getHeight",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 441,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 441,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 441,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 443,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "offsetY",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 443,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 443,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 443,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "offsetY",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 444,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 444,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 445,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 445,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "tmp",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 445,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 445,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetY",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "tmp",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 446,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 446,
                                                    "char": 30
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 447,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 449,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 449,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "opacity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 449,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 449,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 449,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "opacity",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                "line": 450,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 450,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 451,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 451,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 451,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 451,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "opacity",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "100",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                        "line": 452,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                                    "line": 452,
                                                    "char": 30
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 453,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 455,
                                    "char": 12
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 455,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 455,
                                    "char": 14
                                },
                                "name": "processWatermark",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "watermark",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 455,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 455,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 455,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 455,
                                        "char": 52
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 455,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 455,
                                        "char": 61
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                            "line": 455,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                        "line": 455,
                                        "char": 70
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 455,
                                "char": 71
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 457,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 457,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                            "line": 458,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Add a watermark to an image with the specified opacity\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                    "line": 430,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                                "line": 430,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                        "line": 430,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
                    "line": 429,
                    "last-line": 459,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
            "line": 21,
            "char": 14
        },
        "file": "\/app\/phalcon\/Image\/Adapter\/AbstractAdapter.zep",
        "line": 21,
        "char": 14
    }
]