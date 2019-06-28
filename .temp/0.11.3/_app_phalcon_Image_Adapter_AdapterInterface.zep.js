[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Image\\Adapter",
        "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
        "line": 13,
        "char": 9
    },
    {
        "type": "interface",
        "name": "AdapterInterface",
        "definition": {
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 15,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 15,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 15,
                            "char": 63
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 15,
                    "last-line": 17,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 17,
                            "char": 36
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 17,
                    "last-line": 19,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 19,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 19,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 19,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 19,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 19,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 19,
                            "char": 87
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 19,
                    "last-line": 21,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 21,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 21,
                    "last-line": 23,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 23,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 23,
                            "char": 54
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 23,
                    "last-line": 25,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 25,
                            "char": 40
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 25,
                    "last-line": 27,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 27,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 27,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 27,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 27,
                                "char": 82
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 27,
                            "char": 82
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 27,
                    "last-line": 29,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 29,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 29,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 29,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 29,
                            "char": 64
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 29,
                    "last-line": 31,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 31,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 31,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 31,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 31,
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
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                    "line": 31,
                                    "char": 89
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "AUTO",
                                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                    "line": 31,
                                    "char": 89
                                },
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 31,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 31,
                            "char": 89
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 31,
                    "last-line": 33,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 33,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 33,
                    "last-line": 35,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 35,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 35,
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
                                "value": "100",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 35,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 35,
                            "char": 63
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 35,
                    "last-line": 37,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 37,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 37,
                    "last-line": 39,
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
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 37
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 39,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 54
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 39,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 71
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 39,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 90
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 39,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 113
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 39,
                                "char": 128
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 128
                        },
                        {
                            "type": "parameter",
                            "name": "fontfile",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 39,
                                "char": 152
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 39,
                            "char": 152
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 39,
                    "last-line": 41,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 41,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 41,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 41,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 41,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 41,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 41,
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
                                "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                                "line": 41,
                                "char": 112
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                            "line": 41,
                            "char": 112
                        }
                    ],
                    "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
                    "line": 41,
                    "last-line": 42,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
            "line": 42,
            "char": 1
        },
        "file": "\/app\/phalcon\/Image\/Adapter\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]