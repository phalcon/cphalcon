[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http",
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\CryptInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 14,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 15,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\FilterInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 16,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\Exception",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 17,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Cookie\\Exception",
                "alias": "CookieException",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 18,
                "char": 53
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Crypt\\Mismatch",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 19,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Session\\ManagerInterface",
                "alias": "SessionManagerInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 20,
                "char": 64
            }
        ],
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Provide OO wrappers to manage a HTTP cookie.\n *",
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "Cookie",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "CookieInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 25,
                "char": 40
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                "line": 26,
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
                    "name": "container",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 29,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "domain",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 31,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "expire",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 33,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "filter",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 35,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "httpOnly",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 37,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 39,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "path",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 41,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "read",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 41,
                        "char": 27
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 43,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "restored",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 43,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 45,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "secure",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "signKey",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 51,
                        "char": 29
                    },
                    "docblock": "**\n     * The cookie's sign key.\n     * @var string|null\n     *",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "useEncryption",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 53,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 55,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "value",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 59,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 61,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 62,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 62,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "expire",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 63,
                                "char": 23
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 63,
                            "char": 23
                        },
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "\/",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 64,
                                "char": 24
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 64,
                            "char": 24
                        },
                        {
                            "type": "parameter",
                            "name": "secure",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 65,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 65,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 66,
                                "char": 29
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 66,
                            "char": 29
                        },
                        {
                            "type": "parameter",
                            "name": "httpOnly",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 68,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 68,
                            "char": 5
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
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 69,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 69,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 71,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 71,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 71,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 71,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 72,
                                            "char": 18
                                        },
                                        "name": "setValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 72,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 72,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 72,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
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
                                    "property": "expire",
                                    "expr": {
                                        "type": "variable",
                                        "value": "expire",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 75,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 75,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 77,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "path",
                                    "expr": {
                                        "type": "variable",
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 77,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 77,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 79,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "secure",
                                    "expr": {
                                        "type": "variable",
                                        "value": "secure",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 79,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 79,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 81,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "domain",
                                    "expr": {
                                        "type": "variable",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 81,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 81,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 83,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "httpOnly",
                                    "expr": {
                                        "type": "variable",
                                        "value": "httpOnly",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 83,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 83,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Http\\Cookie constructor.\n     *",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 60,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__toString",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "string",
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 91,
                                        "char": 30
                                    },
                                    "name": "getValue",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 91,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 91,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 92,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic __toString method converts the cookie's value to string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 90,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 89,
                    "last-line": 96,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 17
                                },
                                {
                                    "variable": "domain",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 25
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 31
                                },
                                {
                                    "variable": "secure",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 39
                                },
                                {
                                    "variable": "httpOnly",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 49
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 60
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 99,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 101,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 101,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 101,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 101,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 101,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "domain",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 102,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 102,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 102,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 102,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 103,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 103,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 103,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 103,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "secure",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 104,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "secure",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 104,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 104,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 104,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "httpOnly",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 105,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "httpOnly",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 105,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 105,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 105,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 107,
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
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "DiInterface",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 107,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 107,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 107,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 107,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 107,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 107,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 109,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 109,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 109,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 109,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 109,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "session",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "SessionManagerInterface",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 110,
                                                    "char": 82
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 110,
                                                        "char": 63
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "session",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 110,
                                                                "char": 81
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 110,
                                                            "char": 81
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 110,
                                                    "char": 82
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 110,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 110,
                                            "char": 82
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 112,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "session",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 112,
                                            "char": 24
                                        },
                                        "name": "exists",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 112,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "session",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 113,
                                                    "char": 25
                                                },
                                                "name": "remove",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "_PHCOOKIE_",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 113,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 113,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 113,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 113,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 113,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 114,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 117,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "value",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 117,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 117,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 119,
                            "char": 17
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "setcookie",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 120,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 120,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 121,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 121,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "sub",
                                            "left": {
                                                "type": "fcall",
                                                "name": "time",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 122,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "691200",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 122,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 122,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 122,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 123,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 123,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 124,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 124,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "secure",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 125,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 125,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "httpOnly",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 127,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 127,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 127,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 128,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deletes the cookie by setting an expire time in the past\n     *",
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 97,
                    "last-line": 132,
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
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 135,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 135,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 135,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 136,
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
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 134,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 133,
                    "last-line": 140,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDomain",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 143,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 143,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 143,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 143,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 144,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 144,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 145,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 147,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 147,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "domain",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 147,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 147,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 148,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the domain that the cookie is available to\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 142,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 142,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 141,
                    "last-line": 152,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getExpiration",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 155,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 155,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 155,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 155,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 156,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 156,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 157,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 159,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 159,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "expire",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 159,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 159,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 160,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current expiration time\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 154,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 154,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 153,
                    "last-line": 164,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHttpOnly",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 167,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 167,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 167,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 167,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 168,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 168,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 169,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 171,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 171,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "httpOnly",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 171,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 171,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 172,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns if the cookie is accessible only through the HTTP protocol\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 166,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 166,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 165,
                    "last-line": 176,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 179,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 179,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 179,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 180,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current cookie's name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 178,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 178,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 177,
                    "last-line": 184,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPath",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 187,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 187,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 187,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 187,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 188,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 188,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 189,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 191,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 191,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "path",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 191,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 191,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 192,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current cookie's path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 186,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 186,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 185,
                    "last-line": 197,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSecure",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 200,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 200,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 200,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 200,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 201,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 201,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 202,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 204,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 204,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "secure",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 204,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 204,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 205,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns whether the cookie must only be sent when the connection is\n     * secure (HTTPS)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 199,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 199,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 198,
                    "last-line": 209,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 210,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 210,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 210,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 210,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 22
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 29
                                },
                                {
                                    "variable": "crypt",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 36
                                },
                                {
                                    "variable": "decryptedValue",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 52
                                },
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 60
                                },
                                {
                                    "variable": "signKey",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 69
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 212,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 214,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 214,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 214,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 214,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 214,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 215,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 215,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 216,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 218,
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
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 218,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 218,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 219,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 219,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 219,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 219,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 221,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 221,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "read",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 221,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 221,
                                    "char": 25
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 221,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 221,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 222,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "_COOKIE",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 222,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 222,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 222,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 222,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 222,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "defaultValue",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 223,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 224,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 226,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 226,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "useEncryption",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 226,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 226,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "container",
                                                    "expr": {
                                                        "type": "type-hint",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "DiInterface",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 227,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 227,
                                                                "char": 52
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 227,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 227,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 227,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 227,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 229,
                                            "char": 18
                                        },
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
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 229,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 229,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 229,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 229,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 229,
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
                                                                    "type": "scall",
                                                                    "dynamic-class": 0,
                                                                    "class": "Exception",
                                                                    "dynamic": 0,
                                                                    "name": "containerServiceNotFound",
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "the 'filter' and 'crypt' services",
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 233,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 233,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 234,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 234,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 234,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 235,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 237,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "crypt",
                                                    "expr": {
                                                        "type": "type-hint",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "CryptInterface",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 237,
                                                            "char": 73
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 237,
                                                                "char": 56
                                                            },
                                                            "name": "getShared",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "crypt",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 237,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 237,
                                                                    "char": 72
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 237,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 237,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 237,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 239,
                                            "char": 18
                                        },
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
                                                            "value": "crypt",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 239,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 239,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 239,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 239,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 239,
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
                                                                    "value": "A dependency which implements CryptInterface is required to use encryption",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 242,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 242,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 242,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 243,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 248,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "signKey",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 248,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "signKey",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 248,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 248,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 248,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 250,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "signKey",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 250,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 250,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 250,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 250,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "decryptedValue",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "crypt",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 254,
                                                                    "char": 48
                                                                },
                                                                "name": "decryptBase64",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 255,
                                                                            "char": 30
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 255,
                                                                        "char": 30
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "signKey",
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 257,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 257,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 257,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 257,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 258,
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
                                                            "variable": "decryptedValue",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "crypt",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 262,
                                                                    "char": 48
                                                                },
                                                                "name": "decryptBase64",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 262,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 262,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 262,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 262,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 263,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 264,
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
                                                    "variable": "decryptedValue",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 265,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 265,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 266,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 271,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "value",
                                            "expr": {
                                                "type": "variable",
                                                "value": "decryptedValue",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 271,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 271,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 273,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "filters",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 273,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 273,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 273,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "filter",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 274,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "filter",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 274,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 274,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 274,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 276,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 276,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 276,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 276,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 276,
                                                "char": 44
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 277,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 277,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 277,
                                                        "char": 43
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "container",
                                                                    "expr": {
                                                                        "type": "type-hint",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "DiInterface",
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 278,
                                                                            "char": 70
                                                                        },
                                                                        "right": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 278,
                                                                                "char": 60
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "container",
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 278,
                                                                                "char": 70
                                                                            },
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 278,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 278,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 278,
                                                                    "char": 70
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 280,
                                                            "char": 26
                                                        },
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
                                                                            "value": "container",
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 280,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 280,
                                                                        "char": 55
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "object",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 280,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 280,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 280,
                                                                "char": 64
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
                                                                                    "type": "scall",
                                                                                    "dynamic-class": 0,
                                                                                    "class": "Exception",
                                                                                    "dynamic": 0,
                                                                                    "name": "containerServiceNotFound",
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "string",
                                                                                                "value": "the 'filter' service",
                                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                                "line": 284,
                                                                                                "char": 33
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                            "line": 284,
                                                                                            "char": 33
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                    "line": 285,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 285,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 285,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 286,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 287,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 289,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "filter",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "FilterInterface",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 289,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 289,
                                                                        "char": 62
                                                                    },
                                                                    "name": "getShared",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "filter",
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 289,
                                                                                "char": 79
                                                                            },
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 289,
                                                                            "char": 79
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 289,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 289,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 289,
                                                            "char": 80
                                                        },
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "filter",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "filter",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 290,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 290,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 291,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 293,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "filter",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 293,
                                                    "char": 31
                                                },
                                                "name": "sanitize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "decryptedValue",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 293,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 293,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filters",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 293,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 293,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 293,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 294,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 299,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "decryptedValue",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 299,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 300,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 302,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 302,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 302,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 302,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 303,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the cookie's value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 211,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 211,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 210,
                    "last-line": 307,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUsingEncryption",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 310,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "useEncryption",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 310,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 310,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 311,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the cookie is using implicit encryption\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 309,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 309,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 308,
                    "last-line": 319,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "restore",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 22
                                },
                                {
                                    "variable": "expire",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 30
                                },
                                {
                                    "variable": "domain",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 38
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 44
                                },
                                {
                                    "variable": "secure",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 52
                                },
                                {
                                    "variable": "httpOnly",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 62
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 322,
                                    "char": 71
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 323,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 325,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 325,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 325,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 325,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 325,
                                "char": 28
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 326,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 326,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 326,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 326,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 328,
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
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 328,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 328,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 328,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 328,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "session",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 329,
                                                            "char": 41
                                                        },
                                                        "name": "getShared",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "session",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 329,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 329,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 329,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 329,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 331,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "session",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 331,
                                                    "char": 28
                                                },
                                                "name": "exists",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 331,
                                                "char": 38
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
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "session",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 332,
                                                                    "char": 46
                                                                },
                                                                "name": "get",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "_PHCOOKIE_",
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 333,
                                                                                "char": 36
                                                                            },
                                                                            "right": {
                                                                                "type": "property-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                    "line": 333,
                                                                                    "char": 43
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "name",
                                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                    "line": 334,
                                                                                    "char": 21
                                                                                },
                                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                                "line": 334,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                            "line": 334,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 334,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 334,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 334,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 336,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "expire",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 336,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 336,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "expire",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 336,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 336,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 336,
                                                        "char": 57
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "expire",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "expire",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 337,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 337,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 338,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 340,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "domain",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 340,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 340,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "domain",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 340,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 340,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 340,
                                                        "char": 57
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "domain",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "domain",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 341,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 341,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 342,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 344,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "path",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 344,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 344,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "path",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 344,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 344,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 344,
                                                        "char": 53
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "path",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "path",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 345,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 345,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 346,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 348,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "secure",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 348,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 348,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "secure",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 348,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 348,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 348,
                                                        "char": 57
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "secure",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "secure",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 349,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 349,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 350,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 352,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "httpOnly",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 352,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "definition",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 352,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "httpOnly",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 352,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 352,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 352,
                                                        "char": 61
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "httpOnly",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "httpOnly",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 353,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 353,
                                                                    "char": 54
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 354,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 355,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 356,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 358,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "restored",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 358,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 358,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 359,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 361,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 361,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 362,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads the cookie-related info from the SESSION to restore the cookie as\n     * it was set.\n     *\n     * This method is automatically called internally so normally you don't\n     * need to call it.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 321,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 321,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 321,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 320,
                    "last-line": 368,
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
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 17
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 24
                                },
                                {
                                    "variable": "expire",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 32
                                },
                                {
                                    "variable": "domain",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 40
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 46
                                },
                                {
                                    "variable": "secure",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 54
                                },
                                {
                                    "variable": "httpOnly",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 64
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 371,
                                    "char": 75
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 372,
                                    "char": 23
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 372,
                                    "char": 32
                                },
                                {
                                    "variable": "crypt",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 372,
                                    "char": 39
                                },
                                {
                                    "variable": "encryptValue",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 372,
                                    "char": 53
                                },
                                {
                                    "variable": "signKey",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 372,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 374,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 374,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 374,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 374,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 374,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 375,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 375,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 375,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 375,
                                    "char": 32
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "expire",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 376,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "expire",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 376,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 376,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 376,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "domain",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 377,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 377,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 377,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 377,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 378,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 378,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 378,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 378,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "secure",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 379,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "secure",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 379,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 379,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 379,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "httpOnly",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 380,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "httpOnly",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 380,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 380,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 380,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 382,
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
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 382,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 382,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 382,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 382,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 384,
                            "char": 10
                        },
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
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 384,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 384,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 384,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 384,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 384,
                                "char": 48
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
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Exception",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the 'session' service",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 386,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 386,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 387,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 387,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 387,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 388,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 390,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 390,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 390,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 392,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "expire",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 392,
                                    "char": 20
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 392,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 392,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "expire",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 393,
                                                    "char": 34
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "expire",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 393,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 393,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 394,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 396,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 396,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 396,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 396,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 397,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 397,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 397,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 398,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 400,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 400,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 400,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 400,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "domain",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 401,
                                                    "char": 34
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "domain",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 401,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 401,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 402,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 404,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "secure",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 404,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 404,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 404,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "secure",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 405,
                                                    "char": 34
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "secure",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 405,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 405,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 406,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 408,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "httpOnly",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 408,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 408,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 408,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "httpOnly",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 409,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "httpOnly",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 409,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 409,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 410,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 415,
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
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 415,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 415,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 415,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "session",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "SessionManagerInterface",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 416,
                                                    "char": 82
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 416,
                                                        "char": 63
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "session",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 416,
                                                                "char": 81
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 416,
                                                            "char": 81
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 416,
                                                    "char": 82
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 416,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 416,
                                            "char": 82
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 418,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "session",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 418,
                                            "char": 24
                                        },
                                        "name": "exists",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 418,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "session",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 419,
                                                    "char": 25
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "_PHCOOKIE_",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 420,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 420,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 420,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 420,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "definition",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 422,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 422,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 422,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 423,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 424,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 426,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 426,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "useEncryption",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 426,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 426,
                                    "char": 33
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 426,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 426,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 426,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 426,
                                "char": 48
                            },
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
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 427,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 427,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 427,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 427,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 427,
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
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Exception",
                                                            "dynamic": 0,
                                                            "name": "containerServiceNotFound",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "the 'filter' service",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 431,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 431,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 432,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 432,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 432,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 433,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 435,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "crypt",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "CryptInterface",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 435,
                                                    "char": 69
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 435,
                                                        "char": 52
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "crypt",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 435,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 435,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 435,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 435,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 435,
                                            "char": 69
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 437,
                                    "char": 14
                                },
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
                                                    "value": "crypt",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 437,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 437,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 437,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 437,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 437,
                                        "char": 48
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
                                                            "value": "A dependency which implements CryptInterface is required to use encryption",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 440,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 440,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 440,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 441,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 447,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "signKey",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 447,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "signKey",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 447,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 447,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 447,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 449,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "signKey",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 449,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 449,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 449,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 449,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "encryptValue",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "crypt",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 450,
                                                            "char": 42
                                                        },
                                                        "name": "encryptBase64",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "cast",
                                                                    "left": "string",
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 451,
                                                                        "char": 35
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 451,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 451,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "signKey",
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 453,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 453,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 453,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 453,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 454,
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
                                                    "variable": "encryptValue",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "crypt",
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 455,
                                                            "char": 42
                                                        },
                                                        "name": "encryptBase64",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "cast",
                                                                    "left": "string",
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                        "line": 457,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                    "line": 457,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 457,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                        "line": 457,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 457,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 458,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 459,
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
                                            "variable": "encryptValue",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 460,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 460,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 461,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 466,
                            "char": 17
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "setcookie",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "encryptValue",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "expire",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "secure",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 67
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "httpOnly",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 466,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 466,
                                        "char": 77
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 466,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 468,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 468,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 469,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sends the cookie to the HTTP client.\n     *\n     * Stores the cookie definition in session.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 370,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 369,
                    "last-line": 473,
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
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 474,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 474,
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
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 476,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 476,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 477,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 475,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 474,
                    "last-line": 481,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDomain",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 482,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 484,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 484,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 484,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 484,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 485,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 485,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 486,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 488,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "domain",
                                    "expr": {
                                        "type": "variable",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 488,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 488,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 490,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 490,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 491,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the domain that the cookie is available to\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 483,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 483,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 483,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 482,
                    "last-line": 495,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setExpiration",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expire",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 496,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 498,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 498,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 498,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 498,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 499,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 499,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 500,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 502,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "expire",
                                    "expr": {
                                        "type": "variable",
                                        "value": "expire",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 502,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 502,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 504,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 504,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 505,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cookie's expiration time\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 497,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 497,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 497,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 496,
                    "last-line": 509,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHttpOnly",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "httpOnly",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 510,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 512,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 512,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 512,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 512,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 513,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 513,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 514,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 516,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "httpOnly",
                                    "expr": {
                                        "type": "variable",
                                        "value": "httpOnly",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 516,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 516,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 518,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 518,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 519,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the cookie is accessible only through the HTTP protocol\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 511,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 511,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 511,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 510,
                    "last-line": 523,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 524,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 526,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 526,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 526,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 526,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 527,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 527,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 528,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 530,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "path",
                                    "expr": {
                                        "type": "variable",
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 530,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 530,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 532,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 532,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 533,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cookie's expiration time\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 525,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 525,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 525,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 524,
                    "last-line": 537,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setSecure",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "secure",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 538,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 540,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "restored",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 540,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 540,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 540,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 541,
                                            "char": 18
                                        },
                                        "name": "restore",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 541,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 542,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 544,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "secure",
                                    "expr": {
                                        "type": "variable",
                                        "value": "secure",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 544,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 544,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 546,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 546,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 547,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the cookie must only be sent when the connection is secure (HTTPS)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 539,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 539,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 539,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 538,
                    "last-line": 559,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setSignKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "signKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 560,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 560,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "signKey",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 562,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 562,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 562,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                            "line": 563,
                                            "char": 18
                                        },
                                        "name": "assertSignKeyIsLongEnough",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "signKey",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 563,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 563,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 563,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 564,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 566,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "signKey",
                                    "expr": {
                                        "type": "variable",
                                        "value": "signKey",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 566,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 566,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 568,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 568,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 569,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cookie's sign key.\n     *\n     * The `$signKey' MUST be at least 32 characters long\n     * and generated using a cryptographically secure pseudo random generator.\n     *\n     * Use NULL to disable cookie signing.\n     *\n     * @see \\Phalcon\\Security\\Random\n     * @throws \\Phalcon\\Http\\Cookie\\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 561,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 561,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 561,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 560,
                    "last-line": 575,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 576,
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
                                    "property": "value",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 578,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 578,
                                    "char": 32
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "read",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 579,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 579,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 581,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 581,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 582,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cookie's value\n     *\n     * @param string value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 577,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 577,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 577,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 576,
                    "last-line": 586,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useEncryption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "useEncryption",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 587,
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
                                    "property": "useEncryption",
                                    "expr": {
                                        "type": "variable",
                                        "value": "useEncryption",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 589,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 589,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 591,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 591,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 592,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the cookie must be encrypted\/decrypted automatically\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 588,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 588,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 588,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 587,
                    "last-line": 598,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "assertSignKeyIsLongEnough",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "signKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 599,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "length",
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 601,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 603,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "length",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "signKey",
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 603,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 603,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 603,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 603,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 605,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "less",
                                    "left": {
                                        "type": "variable",
                                        "value": "length",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 605,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "32",
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 605,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 605,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                "line": 605,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "CookieException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "sprintf",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "The cookie's key should be at least 32 characters long. Current length is %d.",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 608,
                                                                "char": 98
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 608,
                                                            "char": 98
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "length",
                                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                                "line": 610,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                            "line": 610,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                    "line": 611,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                                "line": 611,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                        "line": 611,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                                    "line": 612,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Cookie.zep",
                            "line": 613,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Assert the cookie's key is enough long.\n     *\n     * @throws \\Phalcon\\Http\\Cookie\\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Cookie.zep",
                        "line": 600,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Cookie.zep",
                    "line": 599,
                    "last-line": 614,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Http\/Cookie.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Cookie.zep",
        "line": 25,
        "char": 5
    }
]