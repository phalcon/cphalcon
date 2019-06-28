[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Response",
        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\HeadersInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                "line": 13,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Response\\Headers\n *\n * This class is a bag to manage the response headers\n *",
        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Headers",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "HeadersInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                "line": 21,
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
                    "name": "headers",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                        "line": 22,
                        "char": 27
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 26,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "__set_state",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 27,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 29,
                                    "char": 20
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 29,
                                    "char": 25
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 29,
                                    "char": 32
                                },
                                {
                                    "variable": "dataHeaders",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 29,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 31,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "new",
                                        "class": "self",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 31,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 31,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 33,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "dataHeaders",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 33,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 33,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "headers",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 33,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 33,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 33,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "dataHeaders",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 34,
                                        "char": 43
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                    "line": 35,
                                                    "char": 25
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                            "line": 35,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 35,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                            "line": 35,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 35,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                "line": 35,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 36,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 37,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 39,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "headers",
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 39,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Restore a \\Phalcon\\Http\\Response\\Headers object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "HeadersInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 28,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 28,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                        "line": 28,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 27,
                    "last-line": 44,
                    "char": 26
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 45,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 47,
                                    "char": 20
                                },
                                {
                                    "variable": "headerValue",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 47,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 49,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 49,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 49,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 49,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 49,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 51,
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
                                        "value": "headerValue",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 51,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 51,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 51,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 51,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 51,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 51,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 52,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 55,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "headerValue",
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 55,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 56,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a header value from the internal bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 45,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 46,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 45,
                    "last-line": 60,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 61,
                            "char": 36
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
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 63,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 63,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 63,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 63,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 63,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 63,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a header to be sent at the end of the request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 62,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                        "line": 62,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 61,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "remove",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 69,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 71,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 73,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 73,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 73,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 73,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 74,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 74,
                                    "char": 22
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "header",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 74,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 74,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 75,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "headers",
                                    "expr": {
                                        "type": "variable",
                                        "value": "headers",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 75,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 75,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 76,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a header to be sent at the end of the request\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 69,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "headers",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 83,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 83,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reset set headers\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 81,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "send",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "header",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 91,
                                    "char": 19
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 91,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 93,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "headers_sent",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 93,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 94,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 95,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 97,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 97,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 97,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 97,
                                "char": 44
                            },
                            "key": "header",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 98,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 98,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 98,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "header",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "header",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 100,
                                                                    "char": 28
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": ": ",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 100,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 100,
                                                                "char": 33
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 100,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                            "line": 100,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 100,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                            "line": 102,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 102,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                "line": 102,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 103,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "memstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "header",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 104,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                            "line": 104,
                                                            "char": 33
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": ":",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 104,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                            "line": 104,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                    "line": 104,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "header",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 104,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 104,
                                                                "char": 54
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 104,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 104,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "5",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 104,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 104,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 104,
                                                        "char": 63
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "HTTP\/",
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 104,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                    "line": 104,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                "line": 104,
                                                "char": 71
                                            },
                                            "statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "header",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "header",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 106,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 106,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 108,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 108,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 108,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                    "line": 109,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "header",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "header",
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                        "line": 111,
                                                                        "char": 32
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": ": ",
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                        "line": 111,
                                                                        "char": 36
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 111,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 111,
                                                                "char": 36
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                    "line": 113,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                                "line": 113,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                        "line": 113,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                                    "line": 114,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 115,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 116,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 118,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 118,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 119,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sends the headers to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 90,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 89,
                    "last-line": 123,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 124,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 124,
                            "char": 50
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
                                    "property": "headers",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 126,
                                            "char": 31
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 126,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 126,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 127,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a header to be sent at the end of the request\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 124,
                    "last-line": 131,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRaw",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 132,
                            "char": 41
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
                                    "property": "headers",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "header",
                                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                            "line": 134,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                        "line": 134,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 134,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 135,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a raw header to be sent at the end of the request\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 132,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                    "line": 142,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 142,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current headers as an array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
                    "line": 140,
                    "last-line": 144,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Response\/Headers.zep",
        "line": 20,
        "char": 5
    }
]