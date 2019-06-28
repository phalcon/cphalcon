[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Response",
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\CookieInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 14,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\CookiesInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 15,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 16,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Cookie\\Exception",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 17,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 66,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Response\\Cookies\n *\n * This class is a bag to manage the cookies.\n *\n * A cookies bag is automatically registered as part of the 'response' service\n * in the DI. By default, cookies are automatically encrypted before being sent\n * to the client and are decrypted when retrieved from the user. To set sign key\n * used to generate a message authentication code use\n * `Phalcon\\Http\\Response\\Cookies::setSignKey()`.\n *\n * ```php\n * use Phalcon\\Di;\n * use Phalcon\\Crypt;\n * use Phalcon\\Http\\Response\\Cookies;\n *\n * $di = new Di();\n *\n * $di->set(\n *     'crypt',\n *     function () {\n *         $crypt = new Crypt();\n *\n *         \/\/ The `$key' should have been previously generated in a cryptographically safe way.\n *         $key = \"T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3\";\n *\n *         $crypt->setKey($key);\n *\n *         return $crypt;\n *     }\n * );\n *\n * $di->set(\n *     'cookies',\n *     function () {\n *         $cookies = new Cookies();\n *\n *         \/\/ The `$key' MUST be at least 32 characters long and generated using a\n *         \/\/ cryptographically secure pseudo random generator.\n *         $key = \"#1dj8$=dp?.ak\/\/j1V$~%*0XaK\\xb1\\x8d\\xa9\\x98\\x054t7w!z%C*F-Jk\\x98\\x05\\\\\\x5c\";\n *\n *         $cookies->setSignKey($key);\n *\n *         return $cookies;\n *     }\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 67,
        "char": 5
    },
    {
        "type": "class",
        "name": "Cookies",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "CookiesInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 67,
                "char": 42
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                "line": 68,
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
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 71,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cookies",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 71,
                        "char": 27
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 73,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "registered",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 73,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 78,
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
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 79,
                        "char": 29
                    },
                    "docblock": "**\n     * The cookie's sign key.\n     * @var string|null\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 81,
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
                        "value": "true",
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 81,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 85,
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
                            "name": "useEncryption",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 86,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 86,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "signKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 86,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 86,
                            "char": 81
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
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 88,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 88,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 90,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 90,
                                    "char": 14
                                },
                                "name": "setSignKey",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "signKey",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 90,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 90,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 90,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 91,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Http\\Response\\Cookies constructor\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 86,
                    "last-line": 96,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 97,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cookie",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 99,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 104,
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
                                        "value": "cookie",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 104,
                                        "char": 47
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 104,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "cookies",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 104,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 104,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 104,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 104,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 104,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 104,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 105,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 106,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 108,
                            "char": 14
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "cookie",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 108,
                                    "char": 16
                                },
                                "name": "delete",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 108,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 110,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 110,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deletes a cookie by its name\n     * This method does not removes cookies from the _COOKIE superglobal\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 98,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 98,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 97,
                    "last-line": 115,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 116,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 118,
                                    "char": 22
                                },
                                {
                                    "variable": "encryption",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 118,
                                    "char": 34
                                },
                                {
                                    "variable": "cookie",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 118,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 123,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "cookie",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 123,
                                    "char": 46
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 123,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cookies",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 123,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 123,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 123,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 123,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 123,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cookie",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 124,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 125,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 132,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cookie",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "CookieInterface",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 132,
                                            "char": 91
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 132,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 132,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 132,
                                                "char": 56
                                            },
                                            "name": "get",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "Phalcon\\\\Http\\\\Cookie",
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 132,
                                                        "char": 82
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 132,
                                                    "char": 82
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                    "line": 132,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 132,
                                                                "char": 89
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 132,
                                                        "char": 90
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 132,
                                                    "char": 90
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 132,
                                            "char": 91
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 132,
                                        "char": 91
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 132,
                                    "char": 91
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
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 133,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 133,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 133,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 133,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 135,
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
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 135,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 135,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 135,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 135,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 139,
                                            "char": 20
                                        },
                                        "name": "setDi",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 139,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 139,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 139,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 141,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "encryption",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 141,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "useEncryption",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 141,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 141,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 141,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 146,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "encryption",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 146,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "cookie",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 147,
                                                    "char": 24
                                                },
                                                "name": "useEncryption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "encryption",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 147,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 147,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 147,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 148,
                                            "char": 22
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "cookie",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 148,
                                                    "char": 24
                                                },
                                                "name": "setSignKey",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 148,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "signKey",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 148,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 148,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 148,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 148,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 149,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 150,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 152,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "cookie",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 152,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a cookie from the bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 117,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 116,
                    "last-line": 157,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCookies",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 160,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cookies",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 160,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 160,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 161,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets all cookies from the bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 159,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 158,
                    "last-line": 165,
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
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 168,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 168,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 168,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 169,
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
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 167,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 167,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 167,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 166,
                    "last-line": 174,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 175,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 177,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "cookies",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 177,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 177,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 177,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 177,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 177,
                                    "char": 43
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "_COOKIE",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 177,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 177,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 177,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 177,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 177,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a cookie is defined in the bag or exists in the _COOKIE\n     * superglobal\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 176,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 176,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 175,
                    "last-line": 182,
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
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 185,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "useEncryption",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 185,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 185,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns if the bag is automatically encrypting\/decrypting cookies\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 183,
                    "last-line": 190,
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
                                    "property": "cookies",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 193,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 193,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 195,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 195,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 196,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reset set cookies\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 192,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 192,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 192,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 191,
                    "last-line": 201,
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
                                    "variable": "cookie",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 204,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 206,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "headers_sent",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 206,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 207,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 208,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 210,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 210,
                                    "char": 28
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cookies",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 210,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 210,
                                "char": 37
                            },
                            "value": "cookie",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 211,
                                            "char": 20
                                        },
                                        "name": "send",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 211,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 212,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 214,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 214,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 215,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sends the cookies to the client\n     * Cookies aren't sent if headers are sent in the current request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 203,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 203,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 202,
                    "last-line": 235,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 237,
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
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 238,
                                "char": 21
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 238,
                            "char": 21
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
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 239,
                                "char": 23
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 239,
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
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 240,
                                "char": 24
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 240,
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
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 241,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 241,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 242,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 242,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "httpOnly",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 244,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 244,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cookie",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 245,
                                    "char": 19
                                },
                                {
                                    "variable": "encryption",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 245,
                                    "char": 31
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 245,
                                    "char": 42
                                },
                                {
                                    "variable": "response",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 245,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 247,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "encryption",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 247,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "useEncryption",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 247,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 247,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 247,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 252,
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
                                        "value": "cookie",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 252,
                                        "char": 47
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 252,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "cookies",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 252,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 252,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 252,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 252,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 252,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 252,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "cookie",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "CookieInterface",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 257,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 254,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 254,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 254,
                                                        "char": 51
                                                    },
                                                    "name": "get",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Http\\\\Cookie",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 255,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 255,
                                                            "char": 42
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 33
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 33
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "expire",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 41
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 41
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "path",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 47
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "secure",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "domain",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 63
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "httpOnly",
                                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                            "line": 256,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 256,
                                                                        "char": 73
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 257,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 257,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 257,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 257,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 257,
                                            "char": 18
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 262,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 262,
                                            "char": 20
                                        },
                                        "name": "setDi",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 262,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 262,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 262,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 262,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 262,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 267,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "encryption",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 267,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "cookie",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 268,
                                                    "char": 24
                                                },
                                                "name": "useEncryption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "encryption",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 268,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 268,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 268,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 270,
                                            "char": 22
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "cookie",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 270,
                                                    "char": 24
                                                },
                                                "name": "setSignKey",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 270,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "signKey",
                                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                "line": 270,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 270,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 270,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 270,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 271,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 273,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "cookies",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 273,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "cookie",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 273,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 273,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 274,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 278,
                                            "char": 20
                                        },
                                        "name": "setValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 278,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 278,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 278,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 279,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 279,
                                            "char": 20
                                        },
                                        "name": "setExpiration",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "expire",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 279,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 279,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 279,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 280,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 280,
                                            "char": 20
                                        },
                                        "name": "setPath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 280,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 280,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 280,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 281,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 281,
                                            "char": 20
                                        },
                                        "name": "setSecure",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "secure",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 281,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 281,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 281,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 282,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 282,
                                            "char": 20
                                        },
                                        "name": "setDomain",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "domain",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 282,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 282,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 282,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 283,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 283,
                                            "char": 20
                                        },
                                        "name": "setHttpOnly",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "httpOnly",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 283,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 283,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 283,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 284,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cookie",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 284,
                                            "char": 20
                                        },
                                        "name": "setSignKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 284,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "signKey",
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 284,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 284,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 284,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 284,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 285,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 290,
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
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 290,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "registered",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 290,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 290,
                                    "char": 31
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 290,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 290,
                                "char": 39
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
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 291,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 291,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 291,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 291,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 293,
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
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 293,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 293,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 293,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 293,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 293,
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
                                                                        "value": "the 'response' service",
                                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                        "line": 297,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                                    "line": 297,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 298,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 298,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 298,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 299,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 301,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "response",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 301,
                                                    "char": 38
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "response",
                                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                            "line": 301,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                        "line": 301,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 301,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 301,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 307,
                                    "char": 20
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "response",
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 307,
                                            "char": 22
                                        },
                                        "name": "setCookies",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                    "line": 307,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 307,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 307,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 309,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "registered",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                                "line": 309,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                            "line": 309,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 310,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 312,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 312,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 313,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a cookie to be sent at the end of the request.\n     *\n     * This method overrides any cookie set before with the same name.\n     *\n     * ```php\n     * use Phalcon\\Http\\Response\\Cookies;\n     *\n     * $now = new DateTimeImmutable();\n     * $tomorrow = $now->modify('tomorrow');\n     *\n     * $cookies = new Cookies();\n     * $cookies->set(\n     *     'remember-me',\n     *     json_encode(['user_id' => 1]),\n     *     (int) $tomorrow->format('U'),\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 244,
                                    "char": 29
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 244,
                                "char": 29
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 244,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 236,
                    "last-line": 317,
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
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 318,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 318,
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
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 320,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 320,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 321,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 319,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 318,
                    "last-line": 332,
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
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 333,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 333,
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
                                    "property": "signKey",
                                    "expr": {
                                        "type": "variable",
                                        "value": "signKey",
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 335,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 335,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 337,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 337,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 338,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cookie's sign key.\n     *\n     * The `$signKey' MUST be at least 32 characters long\n     * and generated using a cryptographically secure pseudo random generator.\n     *\n     * Use NULL to disable cookie signing.\n     *\n     * @see \\Phalcon\\Security\\Random\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 334,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 334,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 334,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 333,
                    "last-line": 342,
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
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 343,
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
                                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                        "line": 345,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 345,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 347,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 347,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                            "line": 348,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set if cookies in the bag must be automatically encrypted\/decrypted\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                    "line": 344,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                                "line": 344,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                        "line": 344,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
                    "line": 343,
                    "last-line": 349,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
            "line": 67,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Response\/Cookies.zep",
        "line": 67,
        "char": 5
    }
]