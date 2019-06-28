[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Image\\Adapter",
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Imagick",
                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ImagickDraw",
                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                "line": 14,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ImagickPixel",
                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                "line": 15,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                "line": 16,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image\\Exception",
                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                "line": 17,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 33,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Image\\Adapter\\Imagick\n *\n * Image manipulation support. Allows images to be resized, cropped, etc.\n *\n *```php\n * $image = new \\Phalcon\\Image\\Adapter\\Imagick(\"upload\/test.jpg\");\n *\n * $image->resize(200, 200)->rotate(90)->crop(100, 100);\n *\n * if ($image->save()) {\n *     echo \"success\";\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 34,
        "char": 5
    },
    {
        "type": "class",
        "name": "Imagick",
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
                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                        "line": 36,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 37,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "version",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                        "line": 37,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 41,
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
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 42,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 42,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 42,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 42,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 42,
                            "char": 82
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 44,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 46,
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 46,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "checked",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 46,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 46,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 46,
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 47,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 48,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 50,
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 50,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 50,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 52,
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
                                        "type": "new",
                                        "class": "Imagick",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 52,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 52,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 54,
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 54,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 54,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 54,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 54,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 54,
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
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 55,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "file",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 55,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 55,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 55,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 55,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 55,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 57,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 57,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 57,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 57,
                                                    "char": 38
                                                },
                                                "name": "readImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 57,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "realpath",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 57,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 57,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 57,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 57,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 57,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 57,
                                        "char": 65
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
                                                                    "value": "Imagick::readImage ",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 59,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 59,
                                                                        "char": 49
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "file",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 59,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 59,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 59,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": " failed",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 60,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 60,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 60,
                                                        "char": 18
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 60,
                                                "char": 19
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 61,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 63,
                                    "char": 14
                                },
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
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 63,
                                                    "char": 22
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 63,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 63,
                                                "char": 29
                                            },
                                            "name": "getImageAlphaChannel",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 63,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 63,
                                        "char": 53
                                    },
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
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 64,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 64,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 64,
                                                    "char": 29
                                                },
                                                "name": "setImageAlphaChannel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::ALPHACHANNEL_SET",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 65,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 65,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 66,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 66,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 66,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 67,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 69,
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 69,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 69,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 69,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 69,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 69,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "image",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 70,
                                                                "char": 34
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 70,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 70,
                                                            "char": 41
                                                        },
                                                        "name": "coalesceImages",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 70,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 70,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 72,
                                            "char": 20
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 72,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 72,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 72,
                                                    "char": 29
                                                },
                                                "name": "clear",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 72,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 73,
                                            "char": 20
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 73,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 73,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 73,
                                                    "char": 29
                                                },
                                                "name": "destroy",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 73,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 75,
                                            "char": 19
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
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 75,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 75,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 76,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
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
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 78,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 78,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 78,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 78,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 78,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 78,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 78,
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Failed to create image from file ",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 80,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 80,
                                                                    "char": 62
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "file",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 81,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 81,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 81,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 81,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 81,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 82,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 84,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 84,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 84,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 84,
                                            "char": 25
                                        },
                                        "name": "newImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 85,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 85,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 86,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 86,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "new",
                                                    "class": "ImagickPixel",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "transparent",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 87,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 87,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 88,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 88,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 88,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 90,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 90,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 90,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 90,
                                            "char": 25
                                        },
                                        "name": "setFormat",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "png",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 90,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 90,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 90,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 91,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 91,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 91,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 91,
                                            "char": 25
                                        },
                                        "name": "setImageFormat",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "png",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 91,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 91,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 91,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 93,
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
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 93,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 93,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 93,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 93,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 96,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 96,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 96,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 96,
                                            "char": 39
                                        },
                                        "name": "getImageWidth",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 96,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 96,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 97,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 97,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 97,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 97,
                                            "char": 40
                                        },
                                        "name": "getImageHeight",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 97,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 97,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 98,
                            "char": 11
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 98,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 98,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 98,
                                            "char": 38
                                        },
                                        "name": "getImageType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 98,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 98,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 99,
                            "char": 11
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
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "image\/",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 99,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 99,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 99,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 99,
                                                "char": 47
                                            },
                                            "name": "getImageFormat",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 99,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 99,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 99,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 100,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * \\Phalcon\\Image\\Adapter\\Imagick constructor\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 42,
                    "last-line": 104,
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
                            "type": "if",
                            "expr": {
                                "type": "instanceof",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 107,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 107,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 107,
                                    "char": 33
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "\\Imagick",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 107,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 107,
                                "char": 44
                            },
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 108,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 108,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 108,
                                            "char": 25
                                        },
                                        "name": "clear",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 108,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 109,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 109,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 109,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 109,
                                            "char": 25
                                        },
                                        "name": "destroy",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 109,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 110,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Destroys the loaded image to free up resources.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 105,
                    "last-line": 115,
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
                            "type": "if",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 118,
                                    "char": 26
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "checked",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 118,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 118,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 119,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 122,
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
                                        "name": "class_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "imagick",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 122,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 122,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 122,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 122,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 122,
                                "char": 44
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
                                                    "value": "Imagick is not installed, or the extension is not loaded",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 125,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 125,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 125,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 128,
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
                                            "value": "Imagick::IMAGICK_EXTNUM",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 128,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 128,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 128,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "version",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "constant",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Imagick::IMAGICK_EXTNUM",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 129,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 129,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 129,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 129,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 130,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 132,
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 132,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 132,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 134,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 134,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "checked",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 134,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 134,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 135,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if Imagick is enabled\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 116,
                    "last-line": 139,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getInternalImInstance",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 142,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 142,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "\\Imagick",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 141,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 140,
                    "last-line": 149,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setResourceLimit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 150,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "limit",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 150,
                            "char": 57
                        }
                    ],
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 152,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 152,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 152,
                                    "char": 21
                                },
                                "name": "setResourceLimit",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 152,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 152,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "limit",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 152,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 152,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 152,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the limit for a particular resource in megabytes\n     *\n     * @link http:\/\/php.net\/manual\/ru\/imagick.constants.php#imagick.constants.resourcetypes\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 150,
                    "last-line": 157,
                    "char": 19
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 158,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "g",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 158,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "b",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 158,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 158,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 160,
                                    "char": 23
                                },
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 160,
                                    "char": 30
                                },
                                {
                                    "variable": "pixel1",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 160,
                                    "char": 38
                                },
                                {
                                    "variable": "pixel2",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 160,
                                    "char": 46
                                },
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 160,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 162,
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
                                        "name": "sprintf",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "rgb(%d, %d, %d)",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 162,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 162,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "r",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 162,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 162,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "g",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 162,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 162,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "b",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 162,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 162,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 162,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 162,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 163,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pixel1",
                                    "expr": {
                                        "type": "new",
                                        "class": "ImagickPixel",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "color",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 163,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 163,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 163,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 163,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
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
                                        "type": "div",
                                        "left": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 164,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 164,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 164,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 164,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 166,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pixel2",
                                    "expr": {
                                        "type": "new",
                                        "class": "ImagickPixel",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "transparent",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 166,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 166,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 166,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 166,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 168,
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
                                        "type": "new",
                                        "class": "Imagick",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 168,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 168,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 170,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 170,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 170,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 170,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 170,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 170,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 170,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 172,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "background",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 173,
                                            "char": 24
                                        },
                                        "name": "newImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 173,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 173,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 173,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 173,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 173,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 173,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 173,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 173,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pixel1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 173,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 173,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 173,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 175,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "background",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 175,
                                                "char": 28
                                            },
                                            "name": "getImageAlphaChannel",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 175,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 175,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "background",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 176,
                                                    "char": 28
                                                },
                                                "name": "setImageAlphaChannel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::ALPHACHANNEL_SET",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 177,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 177,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 178,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 178,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 178,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 179,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 181,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "background",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 181,
                                            "char": 24
                                        },
                                        "name": "setImageBackgroundColor",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pixel2",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 181,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 181,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 181,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 183,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "background",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 183,
                                            "char": 24
                                        },
                                        "name": "evaluateImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "constant",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Imagick::EVALUATE_MULTIPLY",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 184,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 184,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 184,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 184,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "opacity",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 185,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 185,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "constant",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Imagick::CHANNEL_ALPHA",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 186,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 186,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 187,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 187,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 187,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 189,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "background",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 189,
                                            "char": 24
                                        },
                                        "name": "setColorspace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 190,
                                                            "char": 22
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "image",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 190,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 190,
                                                        "char": 29
                                                    },
                                                    "name": "getColorspace",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 191,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 191,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 191,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 193,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "background",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 193,
                                                    "char": 34
                                                },
                                                "name": "compositeImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 194,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 194,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 194,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 194,
                                                        "char": 28
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPOSITE_DISSOLVE",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 195,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 195,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 195,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 195,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 196,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 196,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 198,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 198,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 198,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 198,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 200,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 200,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 200,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 200,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 200,
                                        "char": 38
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
                                                            "value": "Imagick::compositeImage failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 201,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 201,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 201,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 202,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 204,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 204,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 204,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 204,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 204,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 204,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 204,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 206,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 207,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 209,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 209,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 209,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 209,
                                    "char": 21
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 209,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 210,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 210,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 210,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 210,
                                    "char": 21
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 210,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 212,
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
                                        "value": "background",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 212,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 212,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 213,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a background.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 158,
                    "last-line": 219,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 220,
                            "char": 46
                        }
                    ],
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 222,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 222,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 222,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 222,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 222,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 222,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 224,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 225,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 225,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 225,
                                            "char": 25
                                        },
                                        "name": "blurImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "radius",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 225,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 225,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "100",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 225,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 225,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 225,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 227,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 227,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 227,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 227,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 227,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 227,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 227,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 229,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 230,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 231,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Blur image\n     *\n     * @param int $radius Blur radius\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 220,
                    "last-line": 235,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 236,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 236,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 236,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 236,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 238,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 240,
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
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 240,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 240,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 240,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 240,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 242,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 242,
                                    "char": 15
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 242,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 242,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 242,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 244,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 245,
                                            "char": 19
                                        },
                                        "name": "cropImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 245,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 245,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 245,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 245,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetX",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 245,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 245,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 245,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 245,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 245,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 246,
                                    "char": 17
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 246,
                                            "char": 19
                                        },
                                        "name": "setImagePage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 246,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 246,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 246,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 246,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 246,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 246,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 246,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 246,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 246,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 248,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 248,
                                                "char": 23
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 248,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 248,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 250,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 251,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 253,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 253,
                                            "char": 34
                                        },
                                        "name": "getImageWidth",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 253,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 253,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 254,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 254,
                                            "char": 34
                                        },
                                        "name": "getImageHeight",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 254,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 254,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 255,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a crop.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 236,
                    "last-line": 259,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 260,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "func",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 262,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 264,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "func",
                                    "expr": {
                                        "type": "string",
                                        "value": "flipImage",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 264,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 264,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 266,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "direction",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 266,
                                    "char": 23
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "\\Phalcon\\Image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 266,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HORIZONTAL",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 266,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 266,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 266,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "func",
                                            "expr": {
                                                "type": "string",
                                                "value": "flopImage",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 267,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 267,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 268,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 270,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 270,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 270,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 270,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 270,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 270,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 270,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 272,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 273,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 273,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 273,
                                            "char": 25
                                        },
                                        "name": "func",
                                        "call-type": 2,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 273,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 275,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 275,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 275,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 275,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 275,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 275,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 275,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 277,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 278,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 279,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a flip.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 260,
                    "last-line": 289,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "processLiquidRescale",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 290,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 290,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "deltaX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 290,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "rigidity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 290,
                            "char": 92
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 292,
                                    "char": 16
                                },
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 292,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 294,
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
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 294,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 294,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 294,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 294,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 296,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 296,
                                    "char": 15
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 296,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 296,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 296,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 298,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 299,
                                                    "char": 29
                                                },
                                                "name": "liquidRescaleImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "width",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 300,
                                                            "char": 22
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 300,
                                                        "char": 22
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "height",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 301,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 301,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "deltaX",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 302,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 302,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "rigidity",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 304,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 304,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 304,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 304,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 306,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 306,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 306,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 306,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 306,
                                        "char": 38
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
                                                            "value": "Imagick::liquidRescale failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 307,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 307,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 307,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 308,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 310,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 310,
                                                "char": 22
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 310,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 310,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 310,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 312,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 313,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 315,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 315,
                                            "char": 33
                                        },
                                        "name": "getImageWidth",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 315,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 315,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 316,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 316,
                                            "char": 34
                                        },
                                        "name": "getImageHeight",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 316,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 316,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 317,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * This method scales the images using liquid rescaling method. Only support\n     * Imagick\n     *\n     * @param int $width   new width\n     * @param int $height  new height\n     * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.\n     * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 290,
                    "last-line": 321,
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
                            "name": "image",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 322,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 322,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mask",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 324,
                                    "char": 17
                                },
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 324,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 326,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask",
                                    "expr": {
                                        "type": "new",
                                        "class": "Imagick",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 326,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 326,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 328,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "mask",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 328,
                                    "char": 14
                                },
                                "name": "readImageBlob",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 329,
                                                "char": 19
                                            },
                                            "name": "render",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 330,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 330,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 330,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 332,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 332,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 332,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 332,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 332,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 332,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 332,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 334,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 335,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 335,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 335,
                                            "char": 25
                                        },
                                        "name": "setImageMatte",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 335,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 335,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 335,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 337,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 337,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 337,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 337,
                                                    "char": 35
                                                },
                                                "name": "compositeImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "mask",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 338,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 338,
                                                        "char": 21
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPOSITE_DSTIN",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 339,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 339,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 339,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 339,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 340,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 340,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 342,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 342,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 342,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 342,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 344,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 344,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 344,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 344,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 344,
                                        "char": 38
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
                                                            "value": "Imagick::compositeImage failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 345,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 345,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 345,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 346,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 348,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 348,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 348,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 348,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 348,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 348,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 348,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 350,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 351,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 353,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "mask",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 353,
                                    "char": 14
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 353,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 354,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "mask",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 354,
                                    "char": 14
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 354,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 355,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Composite one image onto another\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 322,
                    "last-line": 361,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 362,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 364,
                                    "char": 18
                                },
                                {
                                    "variable": "height",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 364,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 366,
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
                                        "type": "div",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 366,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "width",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 366,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 366,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "amount",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 366,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 366,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 366,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 367,
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
                                        "type": "div",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 367,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "height",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 367,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 367,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "amount",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 367,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 367,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 367,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 369,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 369,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 369,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 369,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 369,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 369,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 369,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 371,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 372,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 372,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 372,
                                            "char": 25
                                        },
                                        "name": "scaleImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 372,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 372,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 372,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 372,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 372,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 373,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 373,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 373,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 373,
                                            "char": 25
                                        },
                                        "name": "scaleImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 373,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 373,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 373,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 373,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 373,
                                                        "char": 55
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 373,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 373,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 373,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 373,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 375,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 375,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 375,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 375,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 375,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 375,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 375,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 377,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 378,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 379,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Pixelate image\n     *\n     * @param int $amount amount to pixelate\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 362,
                    "last-line": 383,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 384,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 384,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "fadeIn",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 384,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 386,
                                    "char": 23
                                },
                                {
                                    "variable": "fade",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 386,
                                    "char": 29
                                },
                                {
                                    "variable": "pseudo",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 386,
                                    "char": 37
                                },
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 386,
                                    "char": 44
                                },
                                {
                                    "variable": "pixel",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 386,
                                    "char": 51
                                },
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 386,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 388,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater-equal",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 388,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "version",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 388,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 388,
                                    "char": 26
                                },
                                "right": {
                                    "type": "int",
                                    "value": "30100",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 388,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 388,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reflection",
                                            "expr": {
                                                "type": "clone",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 389,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 389,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 389,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 389,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 389,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 390,
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
                                            "variable": "reflection",
                                            "expr": {
                                                "type": "clone",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 391,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "image",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 391,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 391,
                                                        "char": 48
                                                    },
                                                    "name": "clone",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 391,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 391,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 391,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 392,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 394,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "reflection",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 394,
                                    "char": 20
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 394,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 394,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 394,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 396,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 397,
                                            "char": 24
                                        },
                                        "name": "flipImage",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 397,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 399,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 399,
                                            "char": 24
                                        },
                                        "name": "cropImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "reflection",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 400,
                                                        "char": 28
                                                    },
                                                    "name": "getImageWidth",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 400,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 400,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 401,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 401,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 402,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 402,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 404,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 404,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 404,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 406,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 406,
                                            "char": 24
                                        },
                                        "name": "setImagePage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "reflection",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 407,
                                                        "char": 28
                                                    },
                                                    "name": "getImageWidth",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 407,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 407,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 408,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 408,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 409,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 409,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 411,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 411,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 411,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 413,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "reflection",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 413,
                                                "char": 27
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 413,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 413,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 413,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 415,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 416,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 418,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pseudo",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "variable",
                                            "value": "fadeIn",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 418,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "gradient:black-transparent",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 418,
                                            "char": 58
                                        },
                                        "extra": {
                                            "type": "string",
                                            "value": "gradient:transparent-black",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 418,
                                            "char": 86
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 418,
                                        "char": 86
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 418,
                                    "char": 86
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fade",
                                    "expr": {
                                        "type": "new",
                                        "class": "Imagick",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 419,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 419,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 421,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "fade",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 421,
                                    "char": 14
                                },
                                "name": "newPseudoImage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "reflection",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 422,
                                                "char": 24
                                            },
                                            "name": "getImageWidth",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 422,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 422,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "reflection",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 423,
                                                "char": 24
                                            },
                                            "name": "getImageHeight",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 423,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 423,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pseudo",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 425,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 425,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 425,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 427,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "div-assign",
                                    "variable": "opacity",
                                    "expr": {
                                        "type": "int",
                                        "value": "100",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 427,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 427,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 429,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "reflection",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 429,
                                    "char": 20
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 429,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 429,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 429,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 431,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "reflection",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 432,
                                                    "char": 34
                                                },
                                                "name": "compositeImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fade",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 433,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 433,
                                                        "char": 21
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPOSITE_DSTOUT",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 434,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 434,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 434,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 434,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 435,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 435,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 437,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 437,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 437,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 437,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 439,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 439,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 439,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 439,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 439,
                                        "char": 38
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
                                                            "value": "Imagick::compositeImage failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 440,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 440,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 440,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 441,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 443,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 443,
                                            "char": 24
                                        },
                                        "name": "evaluateImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "constant",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Imagick::EVALUATE_MULTIPLY",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 444,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 444,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 444,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 444,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "opacity",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 445,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 445,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "constant",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Imagick::CHANNEL_ALPHA",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 446,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 446,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 447,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 447,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 447,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 449,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "reflection",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 449,
                                                "char": 27
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 449,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 449,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 449,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 451,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 452,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 454,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "fade",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 454,
                                    "char": 14
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 454,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 456,
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
                                        "type": "new",
                                        "class": "Imagick",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 456,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 456,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pixel",
                                    "expr": {
                                        "type": "new",
                                        "class": "ImagickPixel",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 457,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 457,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "height",
                                    "expr": {
                                        "type": "add",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 458,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 458,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 458,
                                                "char": 34
                                            },
                                            "name": "getImageHeight",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 458,
                                            "char": 52
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 458,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 458,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 458,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 460,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 460,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 460,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 460,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 460,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 460,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 460,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 462,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 463,
                                            "char": 19
                                        },
                                        "name": "newImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 463,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 463,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 463,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 463,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 463,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 463,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pixel",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 463,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 463,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 463,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 465,
                                    "char": 17
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 465,
                                            "char": 19
                                        },
                                        "name": "setImageAlphaChannel",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "constant",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Imagick::ALPHACHANNEL_SET",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 466,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 466,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 467,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 467,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 467,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 469,
                                    "char": 17
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 469,
                                            "char": 19
                                        },
                                        "name": "setColorspace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 470,
                                                            "char": 22
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "image",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 470,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 470,
                                                        "char": 29
                                                    },
                                                    "name": "getColorspace",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 471,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 471,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 471,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 473,
                                    "char": 17
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 473,
                                            "char": 19
                                        },
                                        "name": "setImageDelay",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 474,
                                                            "char": 22
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "image",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 474,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 474,
                                                        "char": 29
                                                    },
                                                    "name": "getImageDelay",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 475,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 475,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 475,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 477,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 477,
                                                    "char": 29
                                                },
                                                "name": "compositeImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 478,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "image",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 478,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 478,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 478,
                                                        "char": 28
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPOSITE_SRC",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 479,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 479,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 479,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 479,
                                                        "char": 49
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 480,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 480,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 482,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 482,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 482,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 482,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 484,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 484,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 484,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 484,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 484,
                                        "char": 38
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
                                                            "value": "Imagick::compositeImage failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 485,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 485,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 485,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 486,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 488,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 488,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 488,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 488,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 488,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 488,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 488,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 490,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 491,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 493,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 493,
                                    "char": 15
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 493,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 493,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 493,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 494,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "reflection",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 494,
                                    "char": 20
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 494,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 494,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 494,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 496,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 497,
                                                    "char": 29
                                                },
                                                "name": "compositeImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "reflection",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 498,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 498,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPOSITE_OVER",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 499,
                                                                        "char": 49
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 499,
                                                                    "char": 49
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 499,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 499,
                                                        "char": 50
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 500,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 500,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 501,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "height",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 502,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 502,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 502,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 502,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 502,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 504,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 504,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 504,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 504,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 504,
                                        "char": 38
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
                                                            "value": "Imagick::compositeImage failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 505,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 505,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 505,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 506,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 508,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 508,
                                                    "char": 22
                                                },
                                                "name": "nextImage",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 508,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 508,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 508,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "reflection",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 508,
                                                    "char": 59
                                                },
                                                "name": "nextImage",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 508,
                                                "char": 74
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 508,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 508,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 508,
                                        "char": 82
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 510,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 511,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 513,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "reflection",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 513,
                                    "char": 20
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 513,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 515,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 515,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 515,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 515,
                                    "char": 21
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 515,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 516,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 516,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 516,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 516,
                                    "char": 21
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 516,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 518,
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
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 518,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 518,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 519,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 519,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 519,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 519,
                                            "char": 39
                                        },
                                        "name": "getImageWidth",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 519,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 519,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 520,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 520,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 520,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 520,
                                            "char": 40
                                        },
                                        "name": "getImageHeight",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 520,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 520,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 521,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a reflection.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 384,
                    "last-line": 525,
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
                            "name": "extension",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 526,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "quality",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 526,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 528,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 530,
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
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 530,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 530,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 530,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 530,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 532,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 532,
                                    "char": 15
                                },
                                "name": "setFormat",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "extension",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 532,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 532,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 532,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 533,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 533,
                                    "char": 15
                                },
                                "name": "setImageFormat",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "extension",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 533,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 533,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 533,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 534,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 534,
                                    "char": 15
                                },
                                "name": "stripImage",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 534,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 536,
                            "char": 11
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 536,
                                            "char": 32
                                        },
                                        "name": "getImageType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 536,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 536,
                                    "char": 47
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "mime",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "image\/",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 537,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 537,
                                                "char": 41
                                            },
                                            "name": "getImageFormat",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 537,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 537,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 537,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 539,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcasecmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "extension",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 539,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 539,
                                            "char": 32
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "gif",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 539,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 539,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 539,
                                    "char": 41
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 539,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 539,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 540,
                                            "char": 19
                                        },
                                        "name": "optimizeImageLayers",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 540,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 541,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcasecmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "extension",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 542,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 542,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jpg",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 542,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 542,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 542,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 542,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 542,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcasecmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "extension",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 542,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 542,
                                                        "char": 72
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jpeg",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 542,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 542,
                                                        "char": 78
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 542,
                                                "char": 82
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 542,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 542,
                                            "char": 86
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 542,
                                        "char": 86
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 543,
                                                    "char": 23
                                                },
                                                "name": "setImageCompression",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPRESSION_JPEG",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 544,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 544,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 545,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 545,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 545,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 546,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 548,
                                    "char": 17
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 548,
                                            "char": 19
                                        },
                                        "name": "setImageCompressionQuality",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "quality",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 548,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 548,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 548,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 549,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 551,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 551,
                                    "char": 22
                                },
                                "name": "getImageBlob",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 551,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 552,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a render.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 527,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                        "line": 527,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 526,
                    "last-line": 556,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 557,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 557,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 559,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 561,
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
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 561,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 561,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 561,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 561,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 563,
                            "char": 13
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "image",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 563,
                                    "char": 15
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 563,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 563,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 563,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 565,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 566,
                                            "char": 19
                                        },
                                        "name": "scaleImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 566,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 566,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 566,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 566,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 566,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 568,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 568,
                                                "char": 22
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 568,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 568,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 568,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 570,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 571,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 573,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 573,
                                            "char": 33
                                        },
                                        "name": "getImageWidth",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 573,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 573,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 574,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 574,
                                            "char": 34
                                        },
                                        "name": "getImageHeight",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 574,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 574,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 575,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a resize.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 557,
                    "last-line": 579,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 580,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "pixel",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 582,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 584,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 584,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 584,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 584,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 584,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 584,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 584,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 586,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pixel",
                                    "expr": {
                                        "type": "new",
                                        "class": "ImagickPixel",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 586,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 586,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 588,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 589,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 589,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 589,
                                            "char": 25
                                        },
                                        "name": "rotateImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pixel",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 589,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 589,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "degrees",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 589,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 589,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 589,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 591,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 591,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 591,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 591,
                                            "char": 25
                                        },
                                        "name": "setImagePage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 592,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 592,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 592,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 592,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 593,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 593,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 593,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 593,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 594,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 594,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 596,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 596,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 596,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 598,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 598,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 598,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 598,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 598,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 598,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 598,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 600,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 601,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 603,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 603,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 603,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 603,
                                            "char": 39
                                        },
                                        "name": "getImageWidth",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 603,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 603,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 604,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 604,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 604,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 604,
                                            "char": 40
                                        },
                                        "name": "getImageHeight",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 604,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 604,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 605,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a rotation.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 580,
                    "last-line": 609,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 610,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "quality",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 610,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 612,
                                    "char": 16
                                },
                                {
                                    "variable": "fp",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 612,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 614,
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
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 614,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 614,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "PATHINFO_EXTENSION",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 614,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 614,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 614,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 614,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 616,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 616,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 616,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 616,
                                    "char": 21
                                },
                                "name": "setFormat",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ext",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 616,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 616,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 616,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 617,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 617,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 617,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 617,
                                    "char": 21
                                },
                                "name": "setImageFormat",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ext",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 617,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 617,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 617,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 619,
                            "char": 11
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 619,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 619,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 619,
                                            "char": 38
                                        },
                                        "name": "getImageType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 619,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 619,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 620,
                            "char": 11
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
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "image\/",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 620,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 620,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 620,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 620,
                                                "char": 47
                                            },
                                            "name": "getImageFormat",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 620,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 620,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 620,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 622,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "strcasecmp",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ext",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 622,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 622,
                                            "char": 26
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "gif",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 622,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 622,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 622,
                                    "char": 34
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 622,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 622,
                                "char": 38
                            },
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 623,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 623,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 623,
                                            "char": 25
                                        },
                                        "name": "optimizeImageLayers",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 623,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 625,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fp",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "fopen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 625,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 625,
                                                        "char": 32
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "w",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 625,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 625,
                                                        "char": 35
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 625,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 625,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 627,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 627,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 627,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 627,
                                            "char": 25
                                        },
                                        "name": "writeImagesFile",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fp",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 627,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 627,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 627,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 629,
                                    "char": 18
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "fclose",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fp",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 629,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 629,
                                                "char": 22
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 629,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 631,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 632,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcasecmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ext",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 633,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 633,
                                                        "char": 30
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jpg",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 633,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 633,
                                                        "char": 35
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 633,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 633,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 633,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strcasecmp",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ext",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 633,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 633,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "jpeg",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 633,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 633,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 633,
                                                "char": 68
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 633,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 633,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 633,
                                        "char": 72
                                    },
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
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 634,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 634,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 634,
                                                    "char": 29
                                                },
                                                "name": "setImageCompression",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPRESSION_JPEG",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 635,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 635,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 636,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 636,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 636,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 637,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 639,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "quality",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 639,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 639,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 639,
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
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 640,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 640,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 640,
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
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 641,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 641,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 642,
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
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 642,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "100",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 642,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 642,
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
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 643,
                                                                        "char": 38
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 643,
                                                                    "char": 38
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 644,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 646,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 646,
                                            "char": 20
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 646,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 646,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 646,
                                                    "char": 29
                                                },
                                                "name": "setImageCompressionQuality",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "quality",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 646,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 646,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 646,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 647,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 649,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 649,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 649,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 649,
                                            "char": 25
                                        },
                                        "name": "writeImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 649,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 649,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 649,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 650,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 651,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a save.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 610,
                    "last-line": 655,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 656,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "amount",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "less",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "amount",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 658,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "5",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 658,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 658,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 658,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "5",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 658,
                                            "char": 39
                                        },
                                        "extra": {
                                            "type": "variable",
                                            "value": "amount",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 658,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 658,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 658,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 659,
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
                                        "type": "div",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "mul",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "amount",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 659,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "double",
                                                    "value": "3.0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 659,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 659,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 659,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 659,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 659,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 659,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 661,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 661,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 661,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 661,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 661,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 661,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 661,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 663,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 664,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 664,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 664,
                                            "char": 25
                                        },
                                        "name": "sharpenImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 664,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 664,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "amount",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 664,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 664,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 664,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 666,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 666,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 666,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 666,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 666,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 666,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 666,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 668,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 669,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 670,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a sharpen.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 656,
                    "last-line": 674,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 86
                        },
                        {
                            "type": "parameter",
                            "name": "r",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "g",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 100
                        },
                        {
                            "type": "parameter",
                            "name": "b",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 107
                        },
                        {
                            "type": "parameter",
                            "name": "size",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 117
                        },
                        {
                            "type": "parameter",
                            "name": "fontfile",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 675,
                            "char": 134
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "x",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 677,
                                    "char": 14
                                },
                                {
                                    "variable": "y",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 677,
                                    "char": 17
                                },
                                {
                                    "variable": "draw",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 677,
                                    "char": 23
                                },
                                {
                                    "variable": "color",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 677,
                                    "char": 30
                                },
                                {
                                    "variable": "gravity",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 677,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 679,
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
                                        "type": "div",
                                        "left": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 679,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 679,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 679,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 679,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "draw",
                                    "expr": {
                                        "type": "new",
                                        "class": "ImagickDraw",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 680,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 680,
                                    "char": 37
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "color",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "sprintf",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "rgb(%d, %d, %d)",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 681,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 681,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "r",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 681,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 681,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "g",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 681,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 681,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "b",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 681,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 681,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 681,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 681,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 683,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "draw",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 683,
                                    "char": 14
                                },
                                "name": "setFillColor",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "ImagickPixel",
                                            "dynamic": 0,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "color",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 684,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 684,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 685,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 685,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 685,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 687,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "fontfile",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 687,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "draw",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 688,
                                            "char": 18
                                        },
                                        "name": "setFont",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fontfile",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 688,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 688,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 688,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 689,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 691,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "size",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 691,
                                "char": 17
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "draw",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 692,
                                            "char": 18
                                        },
                                        "name": "setFontSize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "size",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 692,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 692,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 692,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 693,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 695,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "opacity",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 695,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "draw",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 696,
                                            "char": 18
                                        },
                                        "name": "setfillopacity",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "opacity",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 696,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 696,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 696,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 697,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 699,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "gravity",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 699,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 699,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 701,
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
                                        "value": "offsetX",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 701,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 701,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 701,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 701,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "offsetY",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 702,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 702,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "boolean",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 702,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 702,
                                        "char": 42
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
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 703,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 703,
                                                    "char": 32
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offsetY",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 704,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 704,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 706,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "gravity",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "constant",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "Imagick::GRAVITY_CENTER",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 706,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 706,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 706,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 706,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 707,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "offsetY",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 708,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 708,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "int",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 708,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 708,
                                                "char": 42
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
                                                                "type": "cast",
                                                                "left": "int",
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "offsetY",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 709,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 709,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 709,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 711,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "offsetX",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 711,
                                                        "char": 32
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "less",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "y",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 712,
                                                                    "char": 30
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 712,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 712,
                                                                "char": 34
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
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 713,
                                                                                "char": 44
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 713,
                                                                            "char": 44
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "offsetY",
                                                                            "expr": {
                                                                                "type": "mul",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "y",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 714,
                                                                                    "char": 45
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "-1",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 714,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 714,
                                                                                "char": 49
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 714,
                                                                            "char": 49
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "gravity",
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "constant",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "Imagick::GRAVITY_SOUTHEAST",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 715,
                                                                                            "char": 78
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 715,
                                                                                        "char": 78
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 715,
                                                                                "char": 79
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 715,
                                                                            "char": 79
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 716,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
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
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 717,
                                                                                "char": 44
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 717,
                                                                            "char": 44
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "gravity",
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "constant",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "Imagick::GRAVITY_NORTHEAST",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 718,
                                                                                            "char": 78
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 718,
                                                                                        "char": 78
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 718,
                                                                                "char": 79
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 718,
                                                                            "char": 79
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 719,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 720,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "less",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "y",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 721,
                                                                    "char": 30
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 721,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 721,
                                                                "char": 34
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
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 722,
                                                                                "char": 44
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 722,
                                                                            "char": 44
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "offsetY",
                                                                            "expr": {
                                                                                "type": "mul",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "y",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 723,
                                                                                    "char": 45
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "-1",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 723,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 723,
                                                                                "char": 49
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 723,
                                                                            "char": 49
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "gravity",
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "constant",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "Imagick::GRAVITY_SOUTH",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 724,
                                                                                            "char": 74
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 724,
                                                                                        "char": 74
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 724,
                                                                                "char": 75
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 724,
                                                                            "char": 75
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 725,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
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
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 726,
                                                                                "char": 44
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 726,
                                                                            "char": 44
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "gravity",
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "constant",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "Imagick::GRAVITY_NORTH",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 727,
                                                                                            "char": 74
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 727,
                                                                                        "char": 74
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 727,
                                                                                "char": 75
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 727,
                                                                            "char": 75
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 728,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 729,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 730,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 731,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 732,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "offsetX",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 733,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 733,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "int",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 733,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 733,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "x",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "int",
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "offsetX",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 734,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 734,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 734,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 736,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "offsetX",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 736,
                                                "char": 28
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "offsetY",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 737,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 737,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "boolean",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 737,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 737,
                                                        "char": 50
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "offsetY",
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 738,
                                                                "char": 36
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "less",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "x",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 739,
                                                                            "char": 34
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 739,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 739,
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
                                                                                        "type": "mul",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "x",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 740,
                                                                                            "char": 49
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "-1",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 740,
                                                                                            "char": 53
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 740,
                                                                                        "char": 53
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 740,
                                                                                    "char": 53
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "offsetY",
                                                                                    "expr": {
                                                                                        "type": "int",
                                                                                        "value": "0",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 741,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 741,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "gravity",
                                                                                    "expr": {
                                                                                        "type": "fcall",
                                                                                        "name": "constant",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": "Imagick::GRAVITY_SOUTHEAST",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 742,
                                                                                                    "char": 82
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 742,
                                                                                                "char": 82
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 742,
                                                                                        "char": 83
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 742,
                                                                                    "char": 83
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 743,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "else_statements": [
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
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 744,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 744,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "gravity",
                                                                                    "expr": {
                                                                                        "type": "fcall",
                                                                                        "name": "constant",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": "Imagick::GRAVITY_SOUTH",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 745,
                                                                                                    "char": 78
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 745,
                                                                                                "char": 78
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 745,
                                                                                        "char": 79
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 745,
                                                                                    "char": 79
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 746,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 747,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "less",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "x",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 748,
                                                                            "char": 34
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 748,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 748,
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
                                                                                        "type": "mul",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "x",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 749,
                                                                                            "char": 49
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "-1",
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 749,
                                                                                            "char": 53
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 749,
                                                                                        "char": 53
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 749,
                                                                                    "char": 53
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "offsetY",
                                                                                    "expr": {
                                                                                        "type": "int",
                                                                                        "value": "0",
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 750,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 750,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "gravity",
                                                                                    "expr": {
                                                                                        "type": "fcall",
                                                                                        "name": "constant",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": "Imagick::GRAVITY_EAST",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 751,
                                                                                                    "char": 77
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 751,
                                                                                                "char": 77
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 751,
                                                                                        "char": 78
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 751,
                                                                                    "char": 78
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 752,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "else_statements": [
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
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 753,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 753,
                                                                                    "char": 48
                                                                                },
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "gravity",
                                                                                    "expr": {
                                                                                        "type": "fcall",
                                                                                        "name": "constant",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": "Imagick::GRAVITY_WEST",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 754,
                                                                                                    "char": 77
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 754,
                                                                                                "char": 77
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                        "line": 754,
                                                                                        "char": 78
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 754,
                                                                                    "char": 78
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 755,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 756,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 757,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "typeof",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "offsetY",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 758,
                                                                        "char": 44
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 758,
                                                                    "char": 44
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "long",
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 758,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                "line": 758,
                                                                "char": 51
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "x",
                                                                            "expr": {
                                                                                "type": "cast",
                                                                                "left": "int",
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "offsetX",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 759,
                                                                                    "char": 50
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 759,
                                                                                "char": 50
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 759,
                                                                            "char": 50
                                                                        },
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "y",
                                                                            "expr": {
                                                                                "type": "cast",
                                                                                "left": "int",
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "offsetY",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 760,
                                                                                    "char": 50
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 760,
                                                                                "char": 50
                                                                            },
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 760,
                                                                            "char": 50
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 762,
                                                                    "char": 30
                                                                },
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "less",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "x",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 762,
                                                                            "char": 34
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 762,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 762,
                                                                        "char": 38
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "less",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "y",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 763,
                                                                                    "char": 38
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "0",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 763,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 763,
                                                                                "char": 42
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
                                                                                                "type": "mul",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "x",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 764,
                                                                                                    "char": 53
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "-1",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 764,
                                                                                                    "char": 57
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 764,
                                                                                                "char": 57
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 764,
                                                                                            "char": 57
                                                                                        },
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "offsetY",
                                                                                            "expr": {
                                                                                                "type": "mul",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "y",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 765,
                                                                                                    "char": 53
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "-1",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 765,
                                                                                                    "char": 57
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 765,
                                                                                                "char": 57
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 765,
                                                                                            "char": 57
                                                                                        },
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "gravity",
                                                                                            "expr": {
                                                                                                "type": "fcall",
                                                                                                "name": "constant",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "string",
                                                                                                            "value": "Imagick::GRAVITY_SOUTHEAST",
                                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                            "line": 766,
                                                                                                            "char": 86
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                        "line": 766,
                                                                                                        "char": 86
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 766,
                                                                                                "char": 87
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 766,
                                                                                            "char": 87
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 767,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "else_statements": [
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "offsetX",
                                                                                            "expr": {
                                                                                                "type": "mul",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "x",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 768,
                                                                                                    "char": 56
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "-1",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 768,
                                                                                                    "char": 60
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 768,
                                                                                                "char": 60
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 768,
                                                                                            "char": 60
                                                                                        },
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "gravity",
                                                                                            "expr": {
                                                                                                "type": "fcall",
                                                                                                "name": "constant",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "string",
                                                                                                            "value": "Imagick::GRAVITY_NORTHEAST",
                                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                            "line": 769,
                                                                                                            "char": 86
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                        "line": 769,
                                                                                                        "char": 86
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 769,
                                                                                                "char": 87
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 769,
                                                                                            "char": 87
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 770,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 771,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "else_statements": [
                                                                        {
                                                                            "type": "if",
                                                                            "expr": {
                                                                                "type": "less",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "y",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 772,
                                                                                    "char": 38
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "0",
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 772,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                "line": 772,
                                                                                "char": 42
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
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 773,
                                                                                                "char": 52
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 773,
                                                                                            "char": 52
                                                                                        },
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "offsetY",
                                                                                            "expr": {
                                                                                                "type": "mul",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "y",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 774,
                                                                                                    "char": 53
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "-1",
                                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                    "line": 774,
                                                                                                    "char": 57
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 774,
                                                                                                "char": 57
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 774,
                                                                                            "char": 57
                                                                                        },
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "gravity",
                                                                                            "expr": {
                                                                                                "type": "fcall",
                                                                                                "name": "constant",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "string",
                                                                                                            "value": "Imagick::GRAVITY_SOUTHWEST",
                                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                            "line": 775,
                                                                                                            "char": 86
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                        "line": 775,
                                                                                                        "char": 86
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 775,
                                                                                                "char": 87
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 775,
                                                                                            "char": 87
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 776,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "else_statements": [
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
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 777,
                                                                                                "char": 52
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 777,
                                                                                            "char": 52
                                                                                        },
                                                                                        {
                                                                                            "assign-type": "variable",
                                                                                            "operator": "assign",
                                                                                            "variable": "gravity",
                                                                                            "expr": {
                                                                                                "type": "fcall",
                                                                                                "name": "constant",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "string",
                                                                                                            "value": "Imagick::GRAVITY_NORTHWEST",
                                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                            "line": 778,
                                                                                                            "char": 86
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                        "line": 778,
                                                                                                        "char": 86
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                                "line": 778,
                                                                                                "char": 87
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                            "line": 778,
                                                                                            "char": 87
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                                    "line": 779,
                                                                                    "char": 33
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                            "line": 780,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 781,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 782,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 783,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 784,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 785,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 787,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "draw",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 787,
                                    "char": 14
                                },
                                "name": "setGravity",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "gravity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 787,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 787,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 787,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 789,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 789,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 789,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 789,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 789,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 789,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 789,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 791,
                            "char": 12
                        },
                        {
                            "type": "loop",
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
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 792,
                                            "char": 25
                                        },
                                        "name": "annotateImage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "draw",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 792,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetX",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 792,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offsetY",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 792,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 792,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 65
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 792,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 792,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 792,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 794,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 794,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 794,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 794,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 794,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 794,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 794,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 796,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 797,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 799,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "draw",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 799,
                                    "char": 14
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 799,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 800,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a text\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 675,
                    "last-line": 804,
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
                            "name": "image",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 805,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 805,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "offsetX",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 805,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "offsetY",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 805,
                            "char": 91
                        },
                        {
                            "type": "parameter",
                            "name": "opacity",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 805,
                            "char": 104
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "watermark",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 807,
                                    "char": 22
                                },
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 807,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 809,
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
                                        "type": "div",
                                        "left": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 809,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "100",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 809,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 809,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 809,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "watermark",
                                    "expr": {
                                        "type": "new",
                                        "class": "Imagick",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 810,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 810,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 812,
                            "char": 17
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "watermark",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 812,
                                    "char": 19
                                },
                                "name": "readImageBlob",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "image",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 813,
                                                "char": 19
                                            },
                                            "name": "render",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 814,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 814,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 814,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 816,
                            "char": 17
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "watermark",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 816,
                                    "char": 19
                                },
                                "name": "evaluateImage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "constant",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "Imagick::EVALUATE_MULTIPLY",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 817,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 817,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 817,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 817,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "opacity",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 818,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 818,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "constant",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "Imagick::CHANNEL_ALPHA",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 819,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 819,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 820,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 820,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 820,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 822,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 822,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "image",
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 822,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 822,
                                    "char": 21
                                },
                                "name": "setIteratorIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 822,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 822,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 822,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 824,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ret",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 825,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "image",
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 825,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 825,
                                                    "char": 35
                                                },
                                                "name": "compositeImage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "watermark",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 826,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 826,
                                                        "char": 26
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "constant",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Imagick::COMPOSITE_OVER",
                                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                        "line": 827,
                                                                        "char": 49
                                                                    },
                                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                                    "line": 827,
                                                                    "char": 49
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 827,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 827,
                                                        "char": 50
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "offsetX",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 828,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 828,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "offsetY",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 830,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 830,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 830,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 830,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 832,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "ret",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 832,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 832,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 832,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 832,
                                        "char": 38
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
                                                            "value": "Imagick::compositeImage failed",
                                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                            "line": 833,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                        "line": 833,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 833,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 834,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 836,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 836,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "image",
                                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                    "line": 836,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                                "line": 836,
                                                "char": 28
                                            },
                                            "name": "nextImage",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 836,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 836,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                        "line": 836,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                            "line": 838,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 839,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 841,
                            "char": 17
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "watermark",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 841,
                                    "char": 19
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 841,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 842,
                            "char": 17
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "watermark",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                    "line": 842,
                                    "char": 19
                                },
                                "name": "destroy",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                                "line": 842,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                            "line": 843,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Execute a watermarking.\n     *",
                    "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
                    "line": 805,
                    "last-line": 844,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
            "line": 34,
            "char": 5
        },
        "file": "\/app\/phalcon\/Image\/Adapter\/Imagick.zep",
        "line": 34,
        "char": 5
    }
]