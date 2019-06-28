[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Image\\Adapter",
        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                "line": 13,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image\\Exception",
                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                "line": 14,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Gd",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
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
                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                        "line": 18,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 20,
                    "char": 10
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
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 20,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 20,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 20,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 20,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 20,
                            "char": 82
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "imageinfo",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 22,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 24,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 24,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "checked",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 24,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 24,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 24,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "scall",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "check",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 25,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 26,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 28,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "file",
                                    "expr": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 28,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 28,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 30,
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
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 30,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 30,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 30,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 30,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 30,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "realpath",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "realpath",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 31,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "file",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 31,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 31,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 31,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 31,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 31,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 32,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "imageinfo",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "getimagesize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 32,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "file",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 32,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 32,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 32,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 32,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 32,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 34,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "imageinfo",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 34,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "width",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "imageinfo",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 35,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 35,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 35,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 35,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 36,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "height",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "imageinfo",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 36,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 36,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 36,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 36,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 37,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "type",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "imageinfo",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 37,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "2",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 37,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 37,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 37,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 38,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "mime",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "imageinfo",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 38,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "mime",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 38,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 38,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 38,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 39,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 41,
                                    "char": 18
                                },
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 41,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 41,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 41,
                                        "char": 31
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 42,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "image",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "imagecreatefromgif",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 43,
                                                                                "char": 63
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "file",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 43,
                                                                                "char": 68
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 43,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 43,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 43,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 43,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 44,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 46,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 46,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 46,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "image",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "imagecreatefromjpeg",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 47,
                                                                                "char": 64
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "file",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 47,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 47,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 47,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 47,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 47,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 48,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 50,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 50,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "3",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 50,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "image",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "imagecreatefrompng",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 51,
                                                                                "char": 63
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "file",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 51,
                                                                                "char": 68
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 51,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 51,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 51,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 51,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 52,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 54,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 54,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "15",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 54,
                                                "char": 24
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "image",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "imagecreatefromwbmp",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 55,
                                                                                "char": 64
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "file",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 55,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 55,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 55,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 55,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 55,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 56,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 58,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 58,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "int",
                                                "value": "16",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 58,
                                                "char": 24
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "image",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "imagecreatefromxbm",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 59,
                                                                                "char": 63
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "file",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 59,
                                                                                "char": 68
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 59,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 59,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 59,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 59,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 60,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 62,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 62,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 63,
                                                            "char": 29
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "mime",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 63,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 63,
                                                        "char": 35
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
                                                                                    "value": "Installed GD does not support ",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 65,
                                                                                    "char": 60
                                                                                },
                                                                                "right": {
                                                                                    "type": "property-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 65,
                                                                                        "char": 67
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "mime",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 65,
                                                                                        "char": 73
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 65,
                                                                                    "char": 73
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 65,
                                                                                "char": 73
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": " images",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 66,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 66,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 66,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 66,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 67,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 69,
                                                    "char": 25
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
                                                                    "type": "string",
                                                                    "value": "Installed GD does not support such images",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 71,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 71,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 71,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 72,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 72,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 74,
                                    "char": 26
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesavealpha",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 74,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 74,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 74,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 74,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 74,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 74,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 74,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "or",
                                            "left": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 77,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 77,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 77,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 77,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 77,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 77,
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Failed to create image from file ",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 79,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 79,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "file",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 80,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 80,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 80,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 80,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 80,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 81,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 83,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "image",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagecreatetruecolor",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "width",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 83,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 83,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "height",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 83,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 83,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 83,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 83,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 85,
                                    "char": 30
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagealphablending",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 85,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 85,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 85,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 85,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 85,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 85,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 85,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 86,
                                    "char": 26
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesavealpha",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 86,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 86,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 86,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 86,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 86,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 86,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 86,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 88,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "realpath",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 88,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 88,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 88,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 88,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 89,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "width",
                                            "expr": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 89,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 89,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 90,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "height",
                                            "expr": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 90,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 90,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 91,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "int",
                                                "value": "3",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 91,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 91,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 92,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mime",
                                            "expr": {
                                                "type": "string",
                                                "value": "image\/png",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 92,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 92,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 94,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 20,
                    "last-line": 96,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__destruct",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 98,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 100,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "image",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 100,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 100,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 100,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 100,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 102,
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
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 102,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 102,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "resource",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 102,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 102,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagedestroy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 103,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 103,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 103,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 104,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 96,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "check",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 109,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 111,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 111,
                                    "char": 26
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "checked",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 111,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 111,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 112,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 115,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "gd_info",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 115,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 115,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 115,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 115,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 115,
                                "char": 47
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
                                                    "value": "GD is either not installed or not enabled, check your configuration",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 118,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 118,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 118,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 119,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 121,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "version",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "getVersion",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 121,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 121,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 123,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "version_compare",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "version",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 123,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 123,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "2.0.1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 123,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 123,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ">=",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 123,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 123,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 123,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 123,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 123,
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
                                                        "type": "string",
                                                        "value": "Phalcon\\\\Image\\\\Adapter\\\\GD requires GD version '2.0.1' or greater, you have ",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 125,
                                                        "char": 95
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "version",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 126,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 126,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 126,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 126,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 127,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 129,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "checked",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 129,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 129,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 131,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 131,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "checked",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 131,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 131,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 108,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                        "line": 108,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 107,
                    "last-line": 134,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getVersion",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 136,
                                    "char": 20
                                },
                                {
                                    "variable": "info",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 136,
                                    "char": 26
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 136,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 138,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "gd_info",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 138,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 138,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 138,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 138,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 138,
                                "char": 47
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
                                                    "value": "GD is either not installed or not enabled, check your configuration",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 141,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 141,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 141,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 144,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "version",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 144,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 144,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 146,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "defined",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "GD_VERSION",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 146,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 146,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 146,
                                "char": 32
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
                                                "type": "constant",
                                                "value": "GD_VERSION",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 147,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 147,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 148,
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
                                            "variable": "info",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "gd_info",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 149,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 149,
                                            "char": 33
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "matches",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 150,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 150,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 152,
                                    "char": 14
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
                                                    "value": "\/\\\\d+\\\\.\\\\d+(?:\\\\.\\\\d+)?\/",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 152,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 152,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "info",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 152,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "GD Version",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 152,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 152,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 152,
                                                "char": 70
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "matches",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 152,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 152,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 152,
                                        "char": 81
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
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "matches",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 153,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 153,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 153,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 153,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 154,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 155,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 157,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "version",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 157,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 158,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 134,
                    "last-line": 160,
                    "char": 26
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processBackground",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "r",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 160,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "g",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 160,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "b",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 160,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 160,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "background",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 162,
                                    "char": 23
                                },
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 162,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 164,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "opacity",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "div",
                                                "left": {
                                                    "type": "mul",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "opacity",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 164,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "127",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 164,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 164,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "100",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 164,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 164,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 164,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "127",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 164,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 164,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 164,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 166,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "background",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 166,
                                            "char": 31
                                        },
                                        "name": "processCreate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 166,
                                                        "char": 51
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 166,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 166,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 166,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 166,
                                                        "char": 64
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 166,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 166,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 166,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 166,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 166,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 168,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "color",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecolorallocatealpha",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "background",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 168,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 168,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "r",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 168,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 168,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "g",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 168,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 168,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "b",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 168,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 168,
                                                "char": 64
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "opacity",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 168,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 168,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 168,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 168,
                                    "char": 74
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 170,
                            "char": 26
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagealphablending",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "background",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 170,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 170,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 170,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 170,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 170,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 172,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "imagecopy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "background",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 172,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 172,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 57
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 172,
                                                "char": 64
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 172,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 70
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 172,
                                                "char": 77
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 172,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 172,
                                            "char": 84
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 172,
                                        "char": 84
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 172,
                                "char": 86
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagedestroy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 173,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 173,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 173,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 173,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 173,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 175,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "image",
                                            "expr": {
                                                "type": "variable",
                                                "value": "background",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 175,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 175,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 176,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 177,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 160,
                    "last-line": 179,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processBlur",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "radius",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 179,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 181,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 183,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "i",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 183,
                                        "char": 18
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 183,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 185,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "i",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 185,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "radius",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 185,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 185,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagefilter",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 186,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 186,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 186,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 186,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "IMG_FILTER_GAUSSIAN_BLUR",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 186,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 186,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 186,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 188,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "i",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 188,
                                            "char": 20
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 189,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 190,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 179,
                    "last-line": 192,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processCreate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 192,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 192,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 194,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 196,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "image",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecreatetruecolor",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 196,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 196,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 196,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 196,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 196,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 196,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 198,
                            "char": 26
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagealphablending",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 198,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 198,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 198,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 198,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 198,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 199,
                            "char": 22
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagesavealpha",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 199,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 199,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 199,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 199,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 199,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 201,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "image",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 201,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 202,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 192,
                    "last-line": 204,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processCrop",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 204,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 204,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 204,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 204,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 206,
                                    "char": 18
                                },
                                {
                                    "variable": "rect",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 206,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 208,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "rect",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "x",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 209,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "offsetX",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 209,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 209,
                                                "char": 23
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "y",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 210,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "offsetY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 210,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 210,
                                                "char": 23
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 212,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 212,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 212,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 213,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 214,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 214,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 214,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 214,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 216,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "image",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecrop",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 216,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 216,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 216,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 216,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "rect",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 216,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 216,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 216,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 216,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 218,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagedestroy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 218,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 218,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 218,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 218,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 218,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 220,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "image",
                                    "expr": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 220,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 220,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 221,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "width",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesx",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 221,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 221,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 221,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 221,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 222,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "height",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 222,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 222,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 222,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 222,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 223,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 204,
                    "last-line": 225,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processFlip",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "direction",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 225,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "direction",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 227,
                                    "char": 23
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "\\Phalcon\\Image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 227,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HORIZONTAL",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 227,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 227,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 227,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imageflip",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 228,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 228,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 228,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 228,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "IMG_FLIP_HORIZONTAL",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 228,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 228,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 228,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 229,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imageflip",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 230,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 230,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 230,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 230,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "IMG_FLIP_VERTICAL",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 230,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 230,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 230,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 231,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 232,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 225,
                    "last-line": 234,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processMask",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "mask",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 234,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 234,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "maskImage",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 22
                                },
                                {
                                    "variable": "newimage",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 32
                                },
                                {
                                    "variable": "tempImage",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 43
                                },
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 50
                                },
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 57
                                },
                                {
                                    "variable": "r",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 60
                                },
                                {
                                    "variable": "g",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 63
                                },
                                {
                                    "variable": "b",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 236,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 237,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "mask_width",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 237,
                                    "char": 23
                                },
                                {
                                    "variable": "mask_height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 237,
                                    "char": 36
                                },
                                {
                                    "variable": "x",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 237,
                                    "char": 39
                                },
                                {
                                    "variable": "y",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 237,
                                    "char": 42
                                },
                                {
                                    "variable": "alpha",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 237,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 239,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "maskImage",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecreatefromstring",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "mask",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 240,
                                                        "char": 18
                                                    },
                                                    "name": "render",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 241,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 241,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 241,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 241,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 243,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask_width",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "imagesx",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "maskImage",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 243,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 243,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 243,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 243,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 243,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 244,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask_height",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "imagesy",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "maskImage",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 244,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 244,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 244,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 244,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 244,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 245,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "alpha",
                                    "expr": {
                                        "type": "int",
                                        "value": "127",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 245,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 245,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 247,
                            "char": 22
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagesavealpha",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "maskImage",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 247,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 247,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 247,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 247,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 247,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 249,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newimage",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 249,
                                            "char": 29
                                        },
                                        "name": "processCreate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 249,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 249,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 249,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 249,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 249,
                                                        "char": 62
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 249,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 249,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 249,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 249,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 249,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 251,
                            "char": 22
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagesavealpha",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "newimage",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 251,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 251,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 251,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 251,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 251,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 253,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "color",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecolorallocatealpha",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "newimage",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 253,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 253,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 253,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 253,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 253,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 253,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 253,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 253,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "alpha",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 253,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 253,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 253,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 253,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 255,
                            "char": 17
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagefill",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "newimage",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 255,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 255,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 255,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 255,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 255,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 255,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "color",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 255,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 255,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 255,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 257,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 257,
                                            "char": 17
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 257,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 257,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "mask_width",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 257,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 257,
                                    "char": 39
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 257,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 257,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 257,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "mask_height",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 257,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 257,
                                    "char": 69
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 257,
                                "char": 69
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tempImage",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagecreatetruecolor",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 258,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 258,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 258,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 258,
                                                        "char": 61
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 258,
                                                                "char": 68
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 258,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 258,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 258,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 258,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 258,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 260,
                                    "char": 30
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecopyresampled",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tempImage",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 261,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 261,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "maskImage",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 262,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 262,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 263,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 263,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 264,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 264,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 265,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 265,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 266,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 266,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 267,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 267,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 267,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 267,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 268,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 268,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 268,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 268,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "mask_width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 269,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 269,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "mask_height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 271,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 271,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 271,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 273,
                                    "char": 24
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagedestroy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "maskImage",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 273,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 273,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 273,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 275,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "maskImage",
                                            "expr": {
                                                "type": "variable",
                                                "value": "tempImage",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 275,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 275,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 276,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 278,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "x",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 278,
                                        "char": 18
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 278,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 280,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "x",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 280,
                                    "char": 17
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 280,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "width",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 280,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 280,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 280,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "y",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 281,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 281,
                                            "char": 22
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 283,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "y",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 283,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 283,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 283,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 283,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 283,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "index",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "imagecolorat",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "maskImage",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 284,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 284,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "x",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 284,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 284,
                                                                "char": 54
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "y",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 284,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 284,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 284,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 284,
                                                    "char": 58
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "color",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "imagecolorsforindex",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "maskImage",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 285,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 285,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "index",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 285,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 285,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 285,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 285,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 287,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "color",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 287,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "red",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 287,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 287,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 287,
                                                "char": 37
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "alpha",
                                                            "expr": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "int",
                                                                    "value": "127",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 288,
                                                                    "char": 37
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "intval",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "div",
                                                                                "left": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "color",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 288,
                                                                                        "char": 51
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": "red",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 288,
                                                                                        "char": 55
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 288,
                                                                                    "char": 57
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "2",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 288,
                                                                                    "char": 60
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 288,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 288,
                                                                            "char": 60
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 288,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 288,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 288,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 289,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 291,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "index",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "imagecolorat",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 291,
                                                                        "char": 47
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "image",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 291,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 291,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 291,
                                                                "char": 53
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "x",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 291,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 291,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "y",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 291,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 291,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 291,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 291,
                                                    "char": 60
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "color",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "imagecolorsforindex",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 292,
                                                                        "char": 54
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "image",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 292,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 292,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 292,
                                                                "char": 60
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "index",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 292,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 292,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 292,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 292,
                                                    "char": 68
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "r",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 293,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "red",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 293,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 293,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 293,
                                                    "char": 35
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "g",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 294,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "green",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 294,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 294,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 294,
                                                    "char": 37
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "b",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 295,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "blue",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 295,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 295,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 295,
                                                    "char": 36
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "color",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "imagecolorallocatealpha",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "newimage",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 296,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 296,
                                                                "char": 61
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "r",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 296,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 296,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "g",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 296,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 296,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "b",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 296,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 296,
                                                                "char": 70
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "alpha",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 296,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 296,
                                                                "char": 77
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 296,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 296,
                                                    "char": 78
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 298,
                                            "char": 29
                                        },
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagesetpixel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "newimage",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 298,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 298,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "x",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 298,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 298,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "y",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 298,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 298,
                                                        "char": 45
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 298,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 298,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 298,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 300,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "y",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 300,
                                                    "char": 24
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 301,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 303,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "x",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 303,
                                            "char": 20
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 304,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 306,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagedestroy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 306,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 306,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 306,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 306,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 306,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 307,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagedestroy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "maskImage",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 307,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 307,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 307,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 309,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "image",
                                    "expr": {
                                        "type": "variable",
                                        "value": "newimage",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 309,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 309,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 310,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 234,
                    "last-line": 312,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processPixelate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "amount",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 312,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 314,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 315,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "x",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 315,
                                    "char": 14
                                },
                                {
                                    "variable": "y",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 315,
                                    "char": 17
                                },
                                {
                                    "variable": "x1",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 315,
                                    "char": 21
                                },
                                {
                                    "variable": "y1",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 315,
                                    "char": 25
                                },
                                {
                                    "variable": "x2",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 315,
                                    "char": 29
                                },
                                {
                                    "variable": "y2",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 315,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 317,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "x",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 317,
                                        "char": 18
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 317,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 319,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "x",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 319,
                                    "char": 17
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 319,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "width",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 319,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 319,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 319,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "y",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 320,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 320,
                                            "char": 22
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 322,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "y",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 322,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 322,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 322,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 322,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 322,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "x1",
                                                    "expr": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "x",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 323,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "div",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "amount",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 323,
                                                                "char": 36
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "2",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 323,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 323,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 323,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 323,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 324,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "y1",
                                                    "expr": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "y",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 324,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "div",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "amount",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 324,
                                                                "char": 36
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "2",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 324,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 324,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 324,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 324,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 326,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "or",
                                                    "left": {
                                                        "type": "greater-equal",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "x1",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 326,
                                                            "char": 24
                                                        },
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 326,
                                                                "char": 31
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 326,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 326,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 326,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "greater-equal",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "y1",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 326,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 326,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 326,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 326,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 326,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 326,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 326,
                                                "char": 60
                                            },
                                            "statements": [
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 328,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 330,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "color",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "imagecolorat",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 330,
                                                                        "char": 47
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "image",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 330,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 330,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 330,
                                                                "char": 53
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "x1",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 330,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 330,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "y1",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 330,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 330,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 330,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 330,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 332,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "x2",
                                                    "expr": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "x",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 332,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "amount",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 332,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 332,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 332,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 333,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "y2",
                                                    "expr": {
                                                        "type": "add",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "y",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 333,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "amount",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 333,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 333,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 333,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 335,
                                            "char": 36
                                        },
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagefilledrectangle",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 335,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 335,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 335,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 335,
                                                        "char": 49
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "x",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 335,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 335,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "y",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 335,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 335,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "x2",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 335,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 335,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "y2",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 335,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 335,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "color",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 335,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 335,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 335,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 337,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "add-assign",
                                                    "variable": "y",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "amount",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 337,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 337,
                                                    "char": 31
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 338,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 340,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "add-assign",
                                            "variable": "x",
                                            "expr": {
                                                "type": "variable",
                                                "value": "amount",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 340,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 340,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 341,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 342,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 312,
                    "last-line": 344,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processReflection",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 344,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 344,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "fadeIn",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 344,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reflection",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 346,
                                    "char": 23
                                },
                                {
                                    "variable": "line",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 346,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 347,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "stepping",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 347,
                                    "char": 21
                                },
                                {
                                    "variable": "offset",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 347,
                                    "char": 29
                                },
                                {
                                    "variable": "src_y",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 347,
                                    "char": 36
                                },
                                {
                                    "variable": "dst_y",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 347,
                                    "char": 43
                                },
                                {
                                    "variable": "dst_opacity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 347,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 349,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "opacity",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "round",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "abs",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "sub",
                                                                    "left": {
                                                                        "type": "list",
                                                                        "left": {
                                                                            "type": "div",
                                                                            "left": {
                                                                                "type": "mul",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "opacity",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 349,
                                                                                    "char": 48
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "127",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 349,
                                                                                    "char": 54
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 349,
                                                                                "char": 54
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "100",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 349,
                                                                                "char": 59
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 349,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 349,
                                                                        "char": 61
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "127",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 349,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 349,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 349,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 349,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 349,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 349,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 349,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 349,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 351,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "opacity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 351,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "127",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 351,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 351,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "stepping",
                                            "expr": {
                                                "type": "div",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "sub",
                                                        "left": {
                                                            "type": "int",
                                                            "value": "127",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 352,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "opacity",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 352,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 352,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 352,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 352,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 352,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 352,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 353,
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
                                            "variable": "stepping",
                                            "expr": {
                                                "type": "div",
                                                "left": {
                                                    "type": "int",
                                                    "value": "127",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 354,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 354,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 354,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 354,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 355,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 357,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reflection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 357,
                                            "char": 31
                                        },
                                        "name": "processCreate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 358,
                                                        "char": 18
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 358,
                                                        "char": 24
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 358,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 358,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "add",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 359,
                                                            "char": 18
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "height",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 359,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 359,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 360,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 360,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 360,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 360,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 360,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 362,
                            "char": 17
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagecopy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 363,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 363,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 364,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 364,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 364,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 364,
                                        "char": 24
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 365,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 365,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 366,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 366,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 367,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 367,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 368,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 368,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 369,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 369,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 369,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 369,
                                        "char": 24
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 370,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 371,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 371,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 371,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 371,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 373,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "offset",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 373,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 373,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 375,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "greater-equal",
                                "left": {
                                    "type": "variable",
                                    "value": "height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 375,
                                    "char": 22
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "offset",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 375,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 375,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "src_y",
                                            "expr": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "sub",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 376,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "height",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 376,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 376,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "offset",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 376,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 376,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 376,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 376,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 376,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 377,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "dst_y",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 377,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 377,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 377,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "offset",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 377,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 377,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 377,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 379,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "fadeIn",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 379,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "dst_opacity",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "round",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "add",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "opacity",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 381,
                                                                            "char": 29
                                                                        },
                                                                        "right": {
                                                                            "type": "list",
                                                                            "left": {
                                                                                "type": "mul",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "stepping",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 381,
                                                                                    "char": 41
                                                                                },
                                                                                "right": {
                                                                                    "type": "list",
                                                                                    "left": {
                                                                                        "type": "sub",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "height",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                            "line": 381,
                                                                                            "char": 51
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "offset",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                            "line": 381,
                                                                                            "char": 59
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 381,
                                                                                        "char": 59
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 381,
                                                                                    "char": 60
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 381,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 382,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 382,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 382,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 382,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 382,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 382,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 383,
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
                                                    "variable": "dst_opacity",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "round",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "add",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "opacity",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 385,
                                                                            "char": 29
                                                                        },
                                                                        "right": {
                                                                            "type": "list",
                                                                            "left": {
                                                                                "type": "mul",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "stepping",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 385,
                                                                                    "char": 41
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "offset",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 385,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 385,
                                                                                "char": 49
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 386,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 386,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 386,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 386,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 386,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 386,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 387,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 389,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "line",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 389,
                                                    "char": 29
                                                },
                                                "name": "processCreate",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 389,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 389,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 389,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 389,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 389,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 389,
                                                        "char": 58
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 389,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 389,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 391,
                                    "char": 21
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecopy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "line",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 392,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 392,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 393,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 393,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 393,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 393,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 394,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 394,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 395,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 395,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 396,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 396,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "src_y",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 397,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 397,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 398,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 398,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 398,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 398,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 400,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 400,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 400,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 402,
                                    "char": 23
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagefilter",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "line",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 403,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 403,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "IMG_FILTER_COLORIZE",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 404,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 404,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 405,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 405,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 406,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 406,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 407,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 407,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "dst_opacity",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 409,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 409,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 409,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 411,
                                    "char": 21
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecopy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "reflection",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 412,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 412,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "line",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 413,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 413,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 414,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 414,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "dst_y",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 415,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 415,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 416,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 416,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 417,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 417,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 418,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 418,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 418,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 418,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 420,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 420,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 420,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 422,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "offset",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 422,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 423,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 425,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagedestroy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 425,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 425,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 425,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 425,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 425,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 427,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "image",
                                    "expr": {
                                        "type": "variable",
                                        "value": "reflection",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 427,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 427,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 428,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "width",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesx",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "reflection",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 428,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 428,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 428,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 428,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 429,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "height",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "reflection",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 429,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 429,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 429,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 429,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 430,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 344,
                    "last-line": 432,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processRender",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "ext",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 432,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "quality",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 432,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ext",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ext",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 434,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 434,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 434,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 434,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 436,
                            "char": 16
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 436,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 438,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ext",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 438,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 438,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "gif",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 438,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 438,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 438,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 438,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 438,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagegif",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 439,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 439,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 439,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 439,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 439,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 440,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ext",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 440,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 440,
                                                        "char": 28
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jpg",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 440,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 440,
                                                        "char": 33
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 440,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 440,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 440,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ext",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 440,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 440,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jpeg",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 440,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 440,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 440,
                                                "char": 62
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 440,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 440,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 440,
                                        "char": 66
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagejpeg",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 441,
                                                                "char": 28
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 441,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 441,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 441,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 441,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 441,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "quality",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 441,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 441,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 441,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 442,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 442,
                                    "char": 16
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strcmp",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ext",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 442,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 442,
                                                    "char": 28
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "png",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 442,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 442,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 442,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 442,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 442,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagepng",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 443,
                                                                "char": 27
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 443,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 443,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 443,
                                                        "char": 33
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 443,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 444,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 444,
                                    "char": 16
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strcmp",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ext",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 444,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 444,
                                                    "char": 28
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "wbmp",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 444,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 444,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 444,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 444,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 444,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagewbmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 445,
                                                                "char": 28
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 445,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 445,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 445,
                                                        "char": 34
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 445,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 446,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 446,
                                    "char": 16
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strcmp",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ext",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 446,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 446,
                                                    "char": 28
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "xbm",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 446,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 446,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 446,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 446,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 446,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagexbm",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 447,
                                                                "char": 27
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 447,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 447,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 447,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 447,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 447,
                                                        "char": 39
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 447,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 448,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 448,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
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
                                                            "value": "Installed GD does not support '",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 450,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ext",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 450,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 450,
                                                        "char": 55
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' images",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 451,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 451,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 451,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 451,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 452,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 454,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_get_clean",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 454,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 455,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 432,
                    "last-line": 457,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processResize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 457,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 457,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 459,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 461,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "image",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagescale",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 461,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 461,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 461,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 461,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 461,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 461,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 461,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 461,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 461,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 461,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 463,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagedestroy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 463,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 463,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 463,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 463,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 463,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 465,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "image",
                                    "expr": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 465,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 465,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 466,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "width",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesx",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 466,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 466,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 466,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 466,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 467,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "height",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagesy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 467,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 467,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 467,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 467,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 468,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 457,
                    "last-line": 470,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processRotate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "degrees",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 470,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 472,
                                    "char": 18
                                },
                                {
                                    "variable": "transparent",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 472,
                                    "char": 31
                                },
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 472,
                                    "char": 38
                                },
                                {
                                    "variable": "height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 472,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 474,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "transparent",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecolorallocatealpha",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 475,
                                                        "char": 18
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 475,
                                                        "char": 24
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 475,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 475,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 476,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 476,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 477,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 477,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 478,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 478,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "127",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 480,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 480,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 480,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 480,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 482,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "image",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagerotate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 483,
                                                        "char": 18
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 483,
                                                        "char": 24
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 483,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 483,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "sub",
                                                    "left": {
                                                        "type": "int",
                                                        "value": "360",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 484,
                                                        "char": 17
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "degrees",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 484,
                                                        "char": 26
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 484,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 484,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "transparent",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 485,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 485,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 487,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 487,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 487,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 487,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 489,
                            "char": 22
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagesavealpha",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 489,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 489,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 489,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 489,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 489,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 491,
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
                                        "type": "fcall",
                                        "name": "imagesx",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 491,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 491,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 491,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 491,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 492,
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
                                        "type": "fcall",
                                        "name": "imagesy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 492,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 492,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 492,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 492,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 494,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "imagecopymerge",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 494,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 494,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 57
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 64
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 72
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 494,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 494,
                                        "char": 77
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 494,
                                "char": 79
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagedestroy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 495,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 495,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 495,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 495,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 495,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 497,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "image",
                                            "expr": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 497,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 497,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 498,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "width",
                                            "expr": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 498,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 498,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 499,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "height",
                                            "expr": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 499,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 499,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 500,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 501,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 470,
                    "last-line": 503,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processSave",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 503,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "quality",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 503,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "ext",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 505,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 507,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ext",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "pathinfo",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 507,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 507,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "PATHINFO_EXTENSION",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 507,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 507,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 507,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 507,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 510,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "ext",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 510,
                                    "char": 17
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 510,
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
                                                "type": "fcall",
                                                "name": "image_type_to_extension",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 511,
                                                                "char": 52
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 511,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 511,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 511,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 511,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 511,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 511,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 511,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 512,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 514,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ext",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ext",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 514,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 514,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 514,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 514,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 516,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ext",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 516,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 516,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "gif",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 516,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 516,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 516,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 516,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 516,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 517,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 517,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 518,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mime",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "image_type_to_mime_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 518,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 518,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 518,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 518,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 518,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 518,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 520,
                                    "char": 20
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagegif",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 520,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 520,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 520,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 520,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 520,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 520,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 520,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 522,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 522,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 523,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 525,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strcmp",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ext",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 525,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 525,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "jpg",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 525,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 525,
                                                "char": 27
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 525,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 525,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 525,
                                    "char": 35
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strcmp",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ext",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 525,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 525,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "jpeg",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 525,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 525,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 525,
                                        "char": 56
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 525,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 525,
                                    "char": 60
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 525,
                                "char": 60
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 526,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 526,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 527,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mime",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "image_type_to_mime_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 527,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 527,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 527,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 527,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 527,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 527,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 529,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "quality",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 529,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 529,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 529,
                                        "char": 28
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "less",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "quality",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 530,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 530,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 530,
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
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 531,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 531,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 532,
                                                    "char": 17
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
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 532,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "100",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 532,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 532,
                                                        "char": 40
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
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 533,
                                                                        "char": 38
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 533,
                                                                    "char": 38
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 534,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 536,
                                                    "char": 25
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 536,
                                            "char": 25
                                        },
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagejpeg",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 536,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 536,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 536,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 536,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 536,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 536,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "quality",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 536,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 536,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 536,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 537,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagejpeg",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 538,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 538,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 538,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 538,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 538,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 538,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 538,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 539,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 541,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 541,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 542,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 544,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ext",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 544,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 544,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "png",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 544,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 544,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 544,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 544,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 544,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "int",
                                                "value": "3",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 545,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 545,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 546,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mime",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "image_type_to_mime_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 546,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 546,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 546,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 546,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 546,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 546,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 548,
                                    "char": 20
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagepng",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 548,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 548,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 548,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 548,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 548,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 548,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 548,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 550,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 550,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 551,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 553,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ext",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 553,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 553,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "wbmp",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 553,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 553,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 553,
                                    "char": 31
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 553,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 553,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "int",
                                                "value": "15",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 554,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 554,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 555,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mime",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "image_type_to_mime_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 555,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 555,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 555,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 555,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 555,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 555,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 557,
                                    "char": 21
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagewbmp",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 557,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 557,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 557,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 557,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 557,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 557,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 557,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 559,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 559,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 560,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 562,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ext",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 562,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 562,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "xbm",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 562,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 562,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 562,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 562,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 562,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "int",
                                                "value": "16",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 563,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 563,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 564,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mime",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "image_type_to_mime_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 564,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "type",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 564,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 564,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 564,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 564,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 564,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 566,
                                    "char": 20
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagexbm",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 566,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 566,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 566,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 566,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 566,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 566,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 566,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 568,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 568,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 569,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 571,
                            "char": 13
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
                                                    "value": "Installed GD does not support '",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 572,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "ext",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 572,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 572,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "' images",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 573,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 573,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 573,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 573,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 574,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 503,
                    "last-line": 576,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processSharpen",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "amount",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 576,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "matrix",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 578,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 580,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "amount",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "round",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "abs",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "add",
                                                                    "left": {
                                                                        "type": "int",
                                                                        "value": "-18",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 580,
                                                                        "char": 42
                                                                    },
                                                                    "right": {
                                                                        "type": "list",
                                                                        "left": {
                                                                            "type": "mul",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "amount",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 580,
                                                                                "char": 52
                                                                            },
                                                                            "right": {
                                                                                "type": "double",
                                                                                "value": "0.08",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 580,
                                                                                "char": 58
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 580,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 580,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 580,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 580,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 580,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 580,
                                                    "char": 60
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "int",
                                                        "value": "2",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 580,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 580,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 580,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 580,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 580,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 582,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matrix",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 583,
                                                                "char": 16
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 583,
                                                            "char": 16
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 583,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 583,
                                                            "char": 22
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 583,
                                                                "char": 29
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 583,
                                                            "char": 29
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 583,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 583,
                                                "char": 30
                                            },
                                            {
                                                "value": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 584,
                                                                "char": 16
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 584,
                                                            "char": 16
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "amount",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 584,
                                                                "char": 24
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 584,
                                                            "char": 24
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 584,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 584,
                                                            "char": 28
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 584,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 584,
                                                "char": 29
                                            },
                                            {
                                                "value": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 585,
                                                                "char": 16
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 585,
                                                            "char": 16
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 585,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 585,
                                                            "char": 22
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 585,
                                                                "char": 29
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 585,
                                                            "char": 29
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 586,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 586,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 586,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 586,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 588,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "imageconvolution",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 588,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 588,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 588,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 588,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "matrix",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 588,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 588,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "sub",
                                            "left": {
                                                "type": "variable",
                                                "value": "amount",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 588,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "8",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 588,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 588,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 588,
                                        "char": 60
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 588,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 588,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 588,
                                "char": 65
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "width",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagesx",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 589,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 589,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 589,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 589,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 589,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 589,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 590,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "height",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagesy",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 590,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 590,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 590,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 590,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 590,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 590,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 591,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 592,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 576,
                    "last-line": 594,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processText",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 86
                        },
                        {
                            "type": "parameter",
                            "name": "r",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "g",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 100
                        },
                        {
                            "type": "parameter",
                            "name": "b",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 107
                        },
                        {
                            "type": "parameter",
                            "name": "size",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 117
                        },
                        {
                            "type": "parameter",
                            "name": "fontfile",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 594,
                            "char": 134
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "space",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 596,
                                    "char": 18
                                },
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 596,
                                    "char": 25
                                },
                                {
                                    "variable": "angle",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 596,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 597,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "s0",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 597,
                                        "char": 19
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 597,
                                    "char": 19
                                },
                                {
                                    "variable": "s1",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 597,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 597,
                                    "char": 27
                                },
                                {
                                    "variable": "s4",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 597,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 597,
                                    "char": 35
                                },
                                {
                                    "variable": "s5",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 597,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 597,
                                    "char": 43
                                },
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 597,
                                    "char": 50
                                },
                                {
                                    "variable": "height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 597,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 599,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "opacity",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "round",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "abs",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "sub",
                                                                    "left": {
                                                                        "type": "list",
                                                                        "left": {
                                                                            "type": "div",
                                                                            "left": {
                                                                                "type": "mul",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "opacity",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 599,
                                                                                    "char": 48
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "127",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 599,
                                                                                    "char": 54
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 599,
                                                                                "char": 54
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "100",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 599,
                                                                                "char": 59
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 599,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 599,
                                                                        "char": 61
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "127",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 599,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 599,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 599,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 599,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 599,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 599,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 599,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 599,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 601,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "fontfile",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 601,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "space",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagettfbbox",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "size",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 602,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 602,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 602,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 602,
                                                        "char": 45
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fontfile",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 602,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 602,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 602,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 602,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 602,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 602,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 604,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "space",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 604,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 604,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 604,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 604,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "s0",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "space",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 605,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 605,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 605,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 605,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 605,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 606,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "s1",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "space",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 606,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 606,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 606,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 606,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 606,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 607,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "s4",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "space",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 607,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "4",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 607,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 607,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 607,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 607,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 608,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "s5",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "space",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 608,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "5",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 608,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 608,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 608,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 608,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 609,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 611,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "or",
                                                "left": {
                                                    "type": "or",
                                                    "left": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "s0",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 611,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 611,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "s1",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 611,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 611,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 611,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "s4",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 611,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 611,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 611,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "s5",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 611,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 611,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 611,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 611,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 611,
                                        "char": 52
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
                                                            "value": "Call to imagettfbbox() failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 612,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 612,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 612,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 613,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 615,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "width",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "abs",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "s4",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 615,
                                                                    "char": 33
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "s0",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 615,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 615,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 615,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 615,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "10",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 615,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 615,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 615,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 616,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "height",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "abs",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "s5",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 616,
                                                                    "char": 33
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "s1",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 616,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 616,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 616,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 616,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "10",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 616,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 616,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 616,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 618,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 618,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 618,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 618,
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
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 619,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "width",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 619,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 619,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 619,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 619,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetX",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 619,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 619,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 619,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 620,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 622,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 622,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 622,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 622,
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
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 623,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "height",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 623,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 623,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 623,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 623,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetY",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 623,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 623,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 623,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 624,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 626,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagecolorallocatealpha",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 626,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 626,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 626,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 626,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "r",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 626,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 626,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "g",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 626,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 626,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "b",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 626,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 626,
                                                        "char": 69
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "opacity",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 626,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 626,
                                                        "char": 78
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 626,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 626,
                                            "char": 79
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 628,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "angle",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 628,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 628,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 630,
                                    "char": 24
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagettftext",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 631,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 631,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 631,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 631,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "size",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 632,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 632,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "angle",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 633,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 633,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetX",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 634,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 634,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 635,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 635,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 636,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 636,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fontfile",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 637,
                                                    "char": 25
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 637,
                                                "char": 25
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 639,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 639,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 639,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 640,
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
                                            "variable": "width",
                                            "expr": {
                                                "type": "mul",
                                                "left": {
                                                    "type": "cast",
                                                    "left": "int",
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "imagefontwidth",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 641,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 641,
                                                                "char": 51
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 641,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 641,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "strlen",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "text",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 641,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 641,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 641,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 641,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 641,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 642,
                                    "char": 15
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
                                                    "name": "imagefontheight",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "size",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 642,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 642,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 642,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 642,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 642,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 644,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 644,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 644,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 644,
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
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 645,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "width",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 645,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 645,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "width",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 645,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 645,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetX",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 645,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 645,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 645,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 646,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 648,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 648,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 648,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 648,
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
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 649,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "height",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                    "line": 649,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 649,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 649,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 649,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetY",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 649,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 649,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 649,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 650,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 652,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagecolorallocatealpha",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 652,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 652,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 652,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 652,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "r",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 652,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 652,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "g",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 652,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 652,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "b",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 652,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 652,
                                                        "char": 69
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "opacity",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 652,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 652,
                                                        "char": 78
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 652,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 652,
                                            "char": 79
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 654,
                                    "char": 23
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagestring",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 654,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 654,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 654,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 654,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "size",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 654,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 654,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetX",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 654,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 654,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 654,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 654,
                                                "char": 60
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 654,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 654,
                                                "char": 66
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 654,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 654,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 654,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 655,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 656,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 594,
                    "last-line": 658,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processWatermark",
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 658,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 658,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 658,
                            "char": 82
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 658,
                            "char": 95
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 658,
                            "char": 108
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "overlay",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 660,
                                    "char": 20
                                },
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 660,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 661,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 661,
                                    "char": 18
                                },
                                {
                                    "variable": "height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 661,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 663,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "overlay",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagecreatefromstring",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "watermark",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 664,
                                                        "char": 23
                                                    },
                                                    "name": "render",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 665,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 665,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 665,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 665,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 667,
                            "char": 22
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagesavealpha",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "overlay",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 667,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 667,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 667,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 667,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 667,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 669,
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
                                            "name": "imagesx",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "overlay",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 669,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 669,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 669,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 669,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 669,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 670,
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
                                            "name": "imagesy",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "overlay",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 670,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 670,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 670,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 670,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 670,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 672,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "opacity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 672,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "100",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 672,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 672,
                                "char": 26
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
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "round",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "abs",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "sub",
                                                                            "left": {
                                                                                "type": "list",
                                                                                "left": {
                                                                                    "type": "div",
                                                                                    "left": {
                                                                                        "type": "mul",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "opacity",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                            "line": 675,
                                                                                            "char": 30
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "127",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                            "line": 675,
                                                                                            "char": 36
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 675,
                                                                                        "char": 36
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "int",
                                                                                        "value": "100",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                        "line": 675,
                                                                                        "char": 41
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                    "line": 675,
                                                                                    "char": 41
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 675,
                                                                                "char": 43
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "127",
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                                "line": 676,
                                                                                "char": 17
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                            "line": 676,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                        "line": 676,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                                "line": 677,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 677,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 677,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 677,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 677,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 679,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "color",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "imagecolorallocatealpha",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "overlay",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 680,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 680,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "127",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 681,
                                                            "char": 20
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 681,
                                                        "char": 20
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "127",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 682,
                                                            "char": 20
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 682,
                                                        "char": 20
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "127",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 683,
                                                            "char": 20
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 683,
                                                        "char": 20
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "opacity",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                            "line": 685,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                        "line": 685,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 685,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 685,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 687,
                                    "char": 28
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagelayereffect",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "overlay",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 687,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 687,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "IMG_EFFECT_OVERLAY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 687,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 687,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 687,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 689,
                                    "char": 32
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagefilledrectangle",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "overlay",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 689,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 689,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 689,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 689,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 689,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 689,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 689,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 689,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 689,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 689,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 689,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 689,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 689,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 690,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 692,
                            "char": 26
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "imagealphablending",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 692,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 692,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 692,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 692,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 692,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 692,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 692,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 694,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "imagecopy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 694,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 694,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "overlay",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetX",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "offsetY",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 60
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 63
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 66
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 73
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                            "line": 694,
                                            "char": 81
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 694,
                                        "char": 81
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                "line": 694,
                                "char": 83
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "imagedestroy",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "overlay",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                    "line": 695,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                                "line": 695,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                        "line": 695,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                                    "line": 696,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                            "line": 697,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
                    "line": 658,
                    "last-line": 698,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Image\/Adapter\/Gd.zep",
        "line": 16,
        "char": 5
    }
]